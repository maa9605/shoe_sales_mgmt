<?php
require_once "./includes/dbconnect.inc";

if (!empty($_POST['sales_price'])) {

$listing_id = $_POST['listing_id'];
$item_id = $_POST['item_id'];
$customer = $_POST['customer_id'];
$date_sold = $_POST['date_sold'];
$sales_price = $_POST['sales_price'];
$shipping = $_POST['shipping_cost'];
$platform_fee = $_POST['platform_fee'];
$ad_fee = $_POST['ad_fee'];
$carrier = "1";
$tracking = $_POST['tracking_no'];

$sql = "CALL Insert_Sales ('" . $customer . "', '" . $listing_id . "', '" . $date_sold . "', '" . $sales_price . "', '" . $shipping . "', '" . $platform_fee . "', '" . $ad_fee . "', '" . $carrier . "', '" . $tracking  . "')";


if (mysqli_query($mysqli, $sql)) {
  $alert_type="success";
  $alert_icon="bi bi-check-circle me-1";
  $message = "Item Has been Marked as Sold </br><a href='inventory.php?type=detail&item=" . $_POST['item_id'] . "'>Go Back</a>";
} else {
  $alert_type="danger";
  $alert_icon="bi bi-exclamation-octagon me-1";
  $message = "Error: " . $sql . "<br>" . mysqli_error($mysqli);
}
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
              </div>
             <!-- End List group -->

            </div>
          </div>

        </div>

      </div>
    </section>

  </main><!-- End #main -->


