<?php
//db include 
require_once "./includes/dbconnect.inc";

//need to update to parameteize and sanitize inputs
$sql = "SELECT * FROM tbl_Source";
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
              <h5 class="card-title">Quick Add</h5>

              <!-- Floating Labels Form -->
              <form method="post" action="inventory.php?type=quickadd" class="row g-3">
                <div class="col-md-12">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="description" name="description" placeholder="Description">
                    <label for="floatingName">Description</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="brand" name="brand" placeholder="Brand">
                    <label for="brand">Brand</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="model" name="model" placeholder="Model">
                    <label for="model">Model</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="color" name="color" placeholder="Color">
                    <label for="color">Color</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="date" class="form-control" id="date_aquired" name="date_aquired" placeholder="Date Acquired">
                    <label for="date_aquired">Date Acquired</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating mb-3">
                    <select class="form-select" id="source" name="source" aria-label="Source">
                    <?php	
				if (mysqli_num_rows($result) > 0) {
	  				// output data of each row
	  				while($row = mysqli_fetch_assoc($result)) {
	  					echo "<option value='" . $row['ID'] . "'>" . $row['Source_Name'] . "</option>";
	  				}
				} else {
	  					echo "0 results";
				}

				mysqli_close($mysqli);  

			?>
                    </select>
                    <label for="source">Source</label>
                  </div>
                </div>
                <div class="col-md-3">
                  <div class="col-md-15">
                    <div class="form-floating">
                      <input type="text" class="form-control" id="item_size" name="item_size" placeholder="Size">
                      <label for="item_size">Size</label>
                    </div>
                  </div>
                </div>
                
                <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="cost" name="cost" placeholder="Cost">
                    <label for="cost">Cost</label>
                  </div>
                </div>
                <div class="text-center">
                  <button type="submit" class="btn btn-primary">Submit</button>
                  <button type="reset" class="btn btn-secondary">Reset</button>
                </div>
              </form><!-- End floating Labels Form -->

            </div>
          </div>

        </div>

      </div>
    </section>

  </main><!-- End #main -->
