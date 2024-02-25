<?php
require_once "./includes/dbconnect.inc";

if (!empty($_POST['description'])) {

$desc = $_POST['description'];
$type = $_POST['Type'];
$condition = $_POST['Condition'];
$upper = $_POST['Upper_Material'];
$sole = $_POST['Sole_Material'];
$brand = $_POST['brand'];
$model = $_POST['model'];
$style = $_POST['Style'];
$width = $_POST['Width'];
$weight = $_POST['Weight'];
$vintage = $_POST['Vintage'];
$color = $_POST['color'];
$size = $_POST['item_size'];
$closure = $_POST['Closure'];
$source = $_POST['source'];
$date_aquired = $_POST['date_aquired'];
$category = $_POST['Category'];
$cost = $_POST['cost'];
$comments = $_POST['comments'];
$sql = "UPDATE tbl_Items SET Description='" . $desc . "', Type='" . $type . "', ItemCondition='" . $condition . "', Upper_Material='" . $upper . "', Sole_Material='" . $sole . "', Brand='" . $brand . "', Model='" . $model . "', Style='" . $style . "', Width='" . $width . "', Weight='" . $weight . "', Vintage='" . $vintage . "', Color='" . $color . "', Item_Size='" . $size . "', Closure='" . $closure . "', Source_ID=" . $source . ", Date_Aquired='" . $date_aquired . "', Category='" . $category . "', Cost='" . $cost . "', Comments='" . $comments . "' WHERE ID=" . $_POST['item_id'];


if (mysqli_query($mysqli, $sql)) {
  $alert_type="success";
  $alert_icon="bi bi-check-circle me-1";
  $message = "Item Has been Updated </br><a href='inventory.php?type=detail&item=" . $_POST['item_id'] . "'>Go Back</a>";
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


