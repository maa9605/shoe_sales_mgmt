<?php
require_once "./includes/dbconnect.inc";


$sql = "DELETE FROM tbl_Listing WHERE ID=" . $_GET['listing_id'] ;

if (mysqli_query($mysqli, $sql)) {
  $alert_type="success";
  $alert_icon="bi bi-check-circle me-1";
  $message = "This Listing has been DELETED successfully </br><a href='inventory.php?type=search'>Search Items</a>";
} else {
  $alert_type="danger";
  $alert_icon="bi bi-exclamation-octagon me-1";
  $message = "Error: " . $sql . "<br>" . mysqli_error($mysqli);
}

mysqli_close($mysqli);

?>
<main id="main" class="main">

    <div class="pagetitle">
      <h1>Inventory</h1>
      <nav>
        <ol class="breadcrumb">
          <li class="breadcrumb-item"><a href="index.php">Home</a></li>
          <li class="breadcrumb-item">Inventory</li>
          <li class="breadcrumb-item active"><?php echo ucfirst($_GET['type']); ?> Inventory</li>
        </ol>
      </nav>
    </div><!-- End Page Title -->

    <section class="section">
      <div class="row">
        <div class="col-lg-12">
                
          <div class="card">
            <div class="card-body">
              <h5 class="card-title"><?php echo ucfirst($_GET['type']); ?> Inventory</h5>

              <!-- List group outline -->
              <div class="list-group">
              <?php echo $message; ?>
              	<div class="alert alert-<?php echo $alert_type; ?> alert-dismissible fade show" role="alert">
                	<i class="<?php echo $alert_icon; ?>"></i>
                	  <?php echo $message; ?>
                	<button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
              	</div>
              </div>
              </div>
             <!-- End List group -->

            </div>
          </div>

        </div>

      </div>
    </section>

  </main><!-- End #main -->
