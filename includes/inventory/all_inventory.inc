<?php
require_once "./includes/dbconnect.inc";
$sql = "Select * from All_Inventory";
$result = mysqli_query($mysqli, $sql);
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

              <!-- List group with Advanced Contents -->
              <div class="list-group">
               <!-- Start Inv Table Summary -->
               
                	<?php 
                		if (mysqli_num_rows($result) > 0) {
  				// output data of each row
  					while($row = mysqli_fetch_assoc($result)) {
  						include './includes/inventory/inv_table_summary.inc';
 					 }
				} else {
  				echo "0 results";
				}
			mysqli_close($mysqli);
                	?>
                	
                	
                <!-- End Inv Table Summary -->
              </div>
             <!-- End List group Advanced Content -->

            </div>
          </div>

        </div>

      </div>
    </section>

  </main><!-- End #main -->
