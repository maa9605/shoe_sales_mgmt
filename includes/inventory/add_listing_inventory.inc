<?php
require_once "./includes/dbconnect.inc";
if (!$mysqli)
{
   echo 'Connection failed<br>';
   echo 'Error number: ' . mysqli_connect_errno() . '<br>';
   echo 'Error message: ' . mysqli_connect_error() . '<br>';
   die();
}
if (isset($_POST['item_id'])) {
	
	$id = strip_tags($_POST['item_id']);
	$desc = strip_tags($_POST['desc']);
	$platform = strip_tags($_POST['platform']);
	$list_price = strip_tags($_POST['list_price']);
	$date_listed = date("Y-m-d");
	$status = "1";
	
	$sql = "INSERT INTO tbl_Listing (Platform_ID, Date_Listed, List_Price, Item_ID, Listing_Title, Listing_Description, Status) VALUES ('$platform', '$date_listed', '$list_price', '$id', '$desc', '$desc', '$status')";
	
if (mysqli_query($mysqli, $sql)) {
  $alert_type="success";
  $alert_icon="bi bi-check-circle me-1";
  $message = "New listing created successfully </br><a href='inventory.php?type=detail&item=$id'>Go Back</a>";
} else {
  $alert_type="danger";
  $alert_icon="bi bi-exclamation-octagon me-1";
  $message = "Error: " . $sql . "<br>" . mysqli_error($mysqli);
}

}
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
              </div>
             <!-- End List group -->

            </div>
          </div>

        </div>

      </div>
    </section>

  </main><!-- End #main -->
