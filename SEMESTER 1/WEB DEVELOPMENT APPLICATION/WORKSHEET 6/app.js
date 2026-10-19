"use strict";

const USER_KEY = "lmsUsers";
const LEAVE_KEY = "lmsLeaveRequests";
const SESSION_KEY = "campusConnectSession";

function seedData() {
  if (!localStorage.getItem(USER_KEY)) {
    localStorage.setItem(USER_KEY, JSON.stringify([
      { username: "sanjiv", password: "Student@123", role: "student" },
      { username: "tutor", password: "Tutor@123", role: "tutor" }
    ]));
  }

  if (!localStorage.getItem(LEAVE_KEY)) {
    localStorage.setItem(LEAVE_KEY, JSON.stringify([
      {
        id: 1,
        username: "sanjiv",
        leaveType: "Sick Leave",
        fromDate: "2026-11-14",
        toDate: "2026-11-20",
        reason: "Health is not good",
        status: "Pending"
      },
      {
        id: 2,
        username: "bala",
        leaveType: "Sick Leave",
        fromDate: "2026-10-25",
        toDate: "2026-10-28",
        reason: "Health is not good",
        status: "Pending"
      },
      {
        id: 3,
        username: "kavin",
        leaveType: "Casual Leave",
        fromDate: "2026-10-14",
        toDate: "2026-10-20",
        reason: "Personal work",
        status: "Approved"
      }
    ]));
  }
}

function getUsers() {
  return JSON.parse(localStorage.getItem(USER_KEY) || "[]");
}

function getLeaves() {
  return JSON.parse(localStorage.getItem(LEAVE_KEY) || "[]");
}

function saveLeaves(leaves) {
  localStorage.setItem(LEAVE_KEY, JSON.stringify(leaves));
}

function getSession() {
  return JSON.parse(sessionStorage.getItem(SESSION_KEY) || "null");
}

function showMessage(element, text, success) {
  element.textContent = text;
  element.className = success ? "message success" : "message";
}

function setupLogin() {
  const form = document.getElementById("loginForm");
  if (!form) return;

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    const username = document.getElementById("loginEmail").value.trim();
    const password = document.getElementById("loginPassword").value;
    const role = document.getElementById("roles").value;
    const user = getUsers().find(function (account) {
      return account.username === username &&
        account.password === password &&
        account.role === role;
    });

    if (!user) {
      showMessage(
        document.getElementById("loginMessage"),
        "Invalid username, password, or role.",
        false
      );
      return;
    }

    sessionStorage.setItem(SESSION_KEY, JSON.stringify({
      username: user.username,
      role: user.role
    }));

    window.location.href = user.role === "student"
      ? "dashboard.html"
      : "approval.html";
  });
}

function requireRole(role) {
  const session = getSession();

  if (!session || session.role !== role) {
    window.location.href = "index.html";
    return null;
  }

  return session;
}

function addCell(row, value) {
  const cell = document.createElement("td");
  cell.textContent = value;
  row.appendChild(cell);
  return cell;
}

function addStatusCell(row, status) {
  const cell = document.createElement("td");
  const badge = document.createElement("span");
  badge.className = "status " + status.toLowerCase();
  badge.textContent = status;
  cell.appendChild(badge);
  row.appendChild(cell);
}

function setupStudentPage() {
  const session = requireRole("student");
  if (!session) return;

  document.getElementById("studentName").textContent = session.username;

  const form = document.getElementById("leaveForm");
  const fromInput = document.getElementById("fromDate");
  const toInput = document.getElementById("toDate");
  const message = document.getElementById("leaveMessage");
  const today = new Date().toISOString().slice(0, 10);

  fromInput.min = today;
  toInput.min = today;

  fromInput.addEventListener("change", function () {
    toInput.min = fromInput.value || today;
  });

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    const fromDate = fromInput.value;
    const toDate = toInput.value;
    const reason = document.getElementById("reason").value.trim();

    if (toDate < fromDate) {
      showMessage(message, "To Date must be on or after From Date.", false);
      return;
    }

    if (!reason) {
      showMessage(message, "Please enter a reason for leave.", false);
      return;
    }

    const leaves = getLeaves();
    const nextId = leaves.reduce(function (largestId, leave) {
      return Math.max(largestId, Number(leave.id) || 0);
    }, 0) + 1;

    leaves.push({
      id: nextId,
      username: session.username,
      leaveType: document.getElementById("leaveType").value,
      fromDate: fromDate,
      toDate: toDate,
      reason: reason,
      status: "Pending"
    });

    saveLeaves(leaves);
    form.reset();
    toInput.min = today;
    showMessage(message, "Leave application submitted successfully.", true);
    renderStudentLeaves(session.username);
  });

  renderStudentLeaves(session.username);
}

function renderStudentLeaves(username) {
  const leaves = getLeaves()
    .filter(function (leave) {
      return leave.username === username;
    })
    .sort(function (first, second) {
      return second.id - first.id;
    });

  const rows = document.getElementById("myLeaveRows");
  rows.textContent = "";

  leaves.forEach(function (leave) {
    const row = document.createElement("tr");
    addCell(row, leave.id);
    addCell(row, leave.leaveType);
    addCell(row, leave.fromDate);
    addCell(row, leave.toDate);
    addCell(row, leave.reason);
    addStatusCell(row, leave.status);
    rows.appendChild(row);
  });

  document.getElementById("emptyHistory").hidden = leaves.length > 0;
  document.getElementById("totalCount").textContent = leaves.length;
  document.getElementById("pendingCount").textContent = leaves.filter(
    function (leave) {
      return leave.status === "Pending";
    }
  ).length;
  document.getElementById("approvedCount").textContent = leaves.filter(
    function (leave) {
      return leave.status === "Approved";
    }
  ).length;
}

function setupTutorPage() {
  const session = requireRole("tutor");
  if (!session) return;

  const rows = document.getElementById("allLeaveRows");
  const message = document.getElementById("approvalMessage");

  function renderRequests() {
    const leaves = getLeaves().sort(function (first, second) {
      return second.id - first.id;
    });

    rows.textContent = "";

    leaves.forEach(function (leave) {
      const row = document.createElement("tr");
      addCell(row, leave.id);
      addCell(row, leave.username);
      addCell(row, leave.leaveType);
      addCell(row, leave.fromDate);
      addCell(row, leave.toDate);
      addCell(row, leave.reason);
      addStatusCell(row, leave.status);

      const actionCell = document.createElement("td");
      if (leave.status === "Pending") {
        const buttons = document.createElement("div");
        buttons.className = "action-group";

        ["Approved", "Rejected"].forEach(function (status) {
          const button = document.createElement("button");
          button.type = "button";
          button.textContent = status === "Approved" ? "Approve" : "Reject";
          button.className = status === "Approved" ? "approve-btn" : "reject-btn";
          button.dataset.id = leave.id;
          button.dataset.status = status;
          buttons.appendChild(button);
        });

        actionCell.appendChild(buttons);
      } else {
        actionCell.textContent = "-";
      }

      row.appendChild(actionCell);
      rows.appendChild(row);
    });

    document.getElementById("emptyRequests").hidden = leaves.length > 0;
    document.getElementById("tutorTotal").textContent = leaves.length;
    document.getElementById("tutorPending").textContent = leaves.filter(
      function (leave) {
        return leave.status === "Pending";
      }
    ).length;
    document.getElementById("tutorApproved").textContent = leaves.filter(
      function (leave) {
        return leave.status === "Approved";
      }
    ).length;
  }

  rows.addEventListener("click", function (event) {
    const button = event.target.closest("button[data-id]");
    if (!button) return;

    const leaves = getLeaves();
    const leave = leaves.find(function (item) {
      return item.id === Number(button.dataset.id);
    });

    if (!leave || leave.status !== "Pending") return;

    leave.status = button.dataset.status;
    saveLeaves(leaves);
    renderRequests();
    showMessage(message, "Leave request " + leave.status.toLowerCase() + ".", true);
  });

  renderRequests();
}

function setupLogout() {
  const button = document.getElementById("logoutButton");
  if (!button) return;

  button.addEventListener("click", function () {
    sessionStorage.removeItem(SESSION_KEY);
    window.location.href = "index.html";
  });
}

seedData();
setupLogin();

if (document.getElementById("studentName")) {
  setupStudentPage();
}

if (document.getElementById("allLeaveRows")) {
  setupTutorPage();
}

setupLogout();
