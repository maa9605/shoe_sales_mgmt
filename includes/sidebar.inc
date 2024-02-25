<aside id="sidebar" class="sidebar">

    <ul class="sidebar-nav" id="sidebar-nav">

      <li class="nav-item">
        <a class="nav-link " href="index.php">
          <i class="bi bi-grid"></i>
          <span>Dashboard</span>
        </a>
      </li><!-- End Dashboard Nav -->

      <li class="nav-item">
        <a class="nav-link collapsed" data-bs-target="#inventory-nav" data-bs-toggle="collapse" href="#">
          <i class="bi bi-menu-button-wide"></i><span>Inventory</span><i class="bi bi-chevron-down ms-auto"></i>
        </a>
        <ul id="inventory-nav" class="nav-content collapse " data-bs-parent="#sidebar-nav">
          <li>
            <a href="inventory.php?type=add">
              <i class="bi bi-circle"></i><span>Add</span>
            </a>
          </li>
          <li>
            <a href="inventory.php?type=search">
              <i class="bi bi-circle"></i><span>Search</span>
            </a>
          </li>
          <li>
            <a href="inventory.php?type=all">
              <i class="bi bi-circle"></i><span>Active</span>
            </a>
          </li>
        </ul>
      </li>
      <!-- End Components Nav -->

      <li class="nav-item">
        <a class="nav-link collapsed" data-bs-target="#reports-nav" data-bs-toggle="collapse" href="#">
          <i class="bi bi-journal-text"></i><span>Reports</span><i class="bi bi-chevron-down ms-auto"></i>
        </a>
        <ul id="reports-nav" class="nav-content collapse " data-bs-parent="#sidebar-nav">
          <li>
            <a href="reports.php?type=avgshoe">
              <i class="bi bi-circle"></i><span>Sourcing Report</span>
            </a>
          </li>
          <li>
            <a href="reports.php?type=monthly">
              <i class="bi bi-circle"></i><span>Financial Report</span>
            </a>
          </li>
           <li>
            <a href="reports.php?type=sales">
              <i class="bi bi-circle"></i><span>Sales Report</span>
            </a>
          </li>
        </ul>
      </li>
      <!-- End Reports Nav -->

      <li class="nav-item">
        <a class="nav-link collapsed" data-bs-target="#admin-nav" data-bs-toggle="collapse" href="#">
          <i class="bi bi-layout-text-window-reverse"></i><span>Admin</span><i class="bi bi-chevron-down ms-auto"></i>
        </a>
        <ul id="admin-nav" class="nav-content collapse " data-bs-parent="#sidebar-nav">
          <li>
            <a href="#">
              <i class="bi bi-circle"></i><span>Users</span>
            </a>
          </li>
          <li>
            <a href="#">
              <i class="bi bi-circle"></i><span>Sources</span>
            </a>
          </li>
          <li>
            <a href="#">
              <i class="bi bi-circle"></i><span>Platforms</span>
            </a>
          </li>
          <li>
            <a href="#">
              <i class="bi bi-circle"></i><span>Data Dictionary</span>
            </a>
          </li>
        </ul>
      </li>
      <!-- End Admin Nav -->

      <li class="nav-heading">Pages</li>

      <li class="nav-item">
        <a class="nav-link collapsed" href="#">
          <i class="bi bi-person"></i>
          <span>Profile</span>
        </a>
      </li><!-- End Profile Page Nav -->

      <li class="nav-item">
        <a class="nav-link collapsed" href="#">
          <i class="bi bi-box-arrow-in-right"></i>
          <span>Login</span>
        </a>
      </li><!-- End Login Page Nav -->

    </ul>

  </aside>
