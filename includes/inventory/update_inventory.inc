<?php
require_once "./includes/dbconnect.inc";

$isql = "SELECT * FROM tbl_Items WHERE ID=" . $_GET['item'];

$r = mysqli_query($mysqli, $isql);

while ($obj = $r -> fetch_object()) { 
   	$id = $obj->ID;
   	$desc = $obj->Description;
   	$date_acq = $obj->Date_Aquired;
   	$cost = $obj->Cost;
   	$src_id = $obj->Source_ID;
   	$type = $obj->Type;
   	$condition = $obj->ItemCondition;
   	$item_size = $obj->Item_Size;
   	$upper = $obj->Upper_Material;
   	$sole = $obj->Sole_Material;
   	$brand = $obj->Brand;
   	$model = $obj->Model;
   	$style = $obj->Style;
   	$width = $obj->Width;
   	$color = $obj->Color;
   	$vintage = $obj->Vintage;
   	$closure = $obj->Closure;
   	$category = $obj->Category;
   	$weight = $obj->Weight;
   	$comments = $obj->Comments;
   	$status = $obj->Status;
	}


$sql = "SELECT * FROM tbl_Source";
$result = mysqli_query($mysqli, $sql);

if ($status <> 'SOLD') {
	$update_button = "<button type='submit' class='btn btn-primary'>Update</button>";
} 
else {
	$update_button =  "<button type='submit' class='btn btn-primary disabled'>Update</button>";
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
              <h5 class="card-title">Item Record <u><?php echo $id; ?></u></h5>

              <!-- Floating Labels Form -->
              <form method="post" action="inventory.php?type=updateitem" class="row g-3">
              	<input type="hidden" id="item_id" name="item_id" value='<?php echo $id; ?>'>
                <div class="col-md-12">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="description" name="description" value='<?php echo $desc; ?>' placeholder="Description">
                    <label for="floatingName">Description</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Type" name="Type" value='<?php echo $type; ?>' placeholder="Type">
                    <label for="Type">Type</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Condition" name="Condition" value='<?php echo $condition; ?>' placeholder="Condition">
                    <label for="Condition">Condition</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Upper_Material" name="Upper_Material" value='<?php echo $upper; ?>' placeholder="Upper_Material">
                    <label for="Upper_Material">Upper Material</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Sole_Material" name="Sole_Material" value='<?php echo $sole; ?>' placeholder="Sole_Material">
                    <label for="Sole_Material">Sole Material</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="brand" name="brand" value='<?php echo $brand; ?>' placeholder="Brand">
                    <label for="brand">Brand</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="model" name="model" value='<?php echo $model; ?>' placeholder="Model">
                    <label for="model">Model</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Style" name="Style" value='<?php echo $style; ?>' placeholder="Style">
                    <label for="Style">Style</label>
                  </div>
                </div>
                <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Width" name="Width" value='<?php echo $width; ?>' placeholder="Width">
                    <label for="Width">Width</label>
                  </div>
                </div>
                <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Weight" name="Weight" value='<?php echo $weight; ?>' placeholder="Weight">
                    <label for="Weight">Weight</label>
                  </div>
                </div>
                  <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Vintage" name="Vintage" value='<?php echo $Vintage; ?>' placeholder="Vintage">
                    <label for="Vintage">Vintage</label>
                  </div>
                </div>
                <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Closure" name="Closure" value='<?php echo $closure; ?>' placeholder="Closure">
                    <label for="Closure">Closure</label>
                  </div>
                </div>
                 <div class="col-md-3">
                  <div class="col-md-15">
                    <div class="form-floating">
                      <input type="text" class="form-control" id="item_size" name="item_size" value='<?php echo $item_size; ?>' placeholder="Size">
                      <label for="item_size">Size</label>
                    </div>
                  </div>
                </div>
                
                <div class="col-md-3">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="cost" name="cost" value='<?php echo $cost; ?>' placeholder="Cost">
                    <label for="cost">Cost</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="color" name="color" value='<?php echo $color; ?>' placeholder="Color">
                    <label for="color">Color</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="date" class="form-control" id="date_aquired" name="date_aquired" value='<?php echo $date_acq; ?>' vplaceholder="Date Acquired">
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
	  					
	  					if ($row['ID'] == $src_id) {
	  						echo "<option value='" . $row['ID'] . "' selected='selected' >" . $row['Source_Name'] . "</option>";
	  					} else {
	  						echo "<option value='" . $row['ID'] . "'>" . $row['Source_Name'] . "</option>";
	  					}
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
                 <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="Category" name="Category" value='<?php echo $category; ?>' placeholder="Category">
                    <label for="Category">Category</label>
                  </div>
                </div>
               <div class="col-md-12">
                  <div class="form-floating">
                    <input type="textbox" class="form-control" id="comments" name="comments" value='<?php echo $comments; ?>' placeholder="comments">
                    <label for="comments">Comments</label>
                  </div>
                </div>
                 <div class="col-md-6">
                   <div class="text-left">
                   
                   <?php include './includes/inventory/delete_input_modal.inc'; ?>

                   </div>
                </div>
                <div class="col-md-6">
                   <div class="text-left">
                     <div class="text-right">
                        <?php include './includes/inventory/sold_input_modal.inc'; ?>
                	<?php echo $update_button; ?>
                  	<button type="reset" class="btn btn-secondary">Reset</button>
                     </div>
                   </div>
                </div>
               
                
              </form><!-- End floating Labels Form -->

            </div>
          </div>

        </div>

      </div>
    </section>
 

</main><!-- End #main -->
