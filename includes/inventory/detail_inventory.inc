<?php
require_once "./includes/dbconnect.inc";
require_once "./includes/functions.inc";

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

$listing_sql = "SELECT * FROM All_Listings WHERE Item_ID=" . $id;
$listings = mysqli_query($mysqli, $listing_sql);

$sql = "SELECT * FROM tbl_Source";
$result = mysqli_query($mysqli, $sql);
	if (mysqli_num_rows($result) > 0) {
	// output data of each row
	  	while($row = mysqli_fetch_assoc($result)) {
	  		if ($row['ID'] == $src_id) {
	  			$item_source = $row['Source_Name'];
	  			$src[$row['ID']] = "<option value='" . $row['ID'] . "' selected='selected' >" . $row['Source_Name'] . "</option>";
	  		} else {
	  			$src[$row['ID']] = "<option value='" . $row['ID'] . "'>" . $row['Source_Name'] . "</option>";
	  		}
	  	}
	} else {
	  	$item_source = "0 results";
	}
//mysqli_close($mysqli);  

if ($status <> '7') {
	$update_button = "<button type='submit' class='btn btn-primary'>Update</button>";
	$shoe_img = "listed.jpg";
	$show_detail = "./includes/inventory/price_detail.inc";
} 
else {
	$update_button =  "<button type='submit' class='btn btn-primary disabled'>Update</button>";
	$shoe_img = "sold.jpg";
	$show_detail = "./includes/inventory/sold_detail.inc";
}
?>  

 <main id="main" class="main">

    <div class="pagetitle">
      <h1>Item Detail</h1>
      <nav>
        <ol class="breadcrumb">
          <li class="breadcrumb-item"><a href="index.html">Home</a></li>
          <li class="breadcrumb-item">Inventory</li>
          <li class="breadcrumb-item active">Item Detail</li>
        </ol>
      </nav>
    </div><!-- End Page Title -->

    <section class="section profile">
      <div class="row">
                 
	
        <div class="col-xl-8">

          <div class="card">
            <div class="card-body pt-3">
             <!-- Default Tabs -->
              <ul class="nav nav-tabs" id="myTab" role="tablist">
                <li class="nav-item" role="presentation">
                  <button class="nav-link active" id="detail-tab" data-bs-toggle="tab" data-bs-target="#detail" type="button" role="tab" aria-controls="detail" aria-selected="true">Detail</button>
                </li>
                <li class="nav-item" role="presentation">
                  <button class="nav-link" id="edit-tab" data-bs-toggle="tab" data-bs-target="#edit" type="button" role="tab" aria-controls="edit" aria-selected="false">Edit</button>
                </li>
                <li class="nav-item" role="presentation">
                  <button class="nav-link" id="listings-tab" data-bs-toggle="tab" data-bs-target="#listings" type="button" role="tab" aria-controls="listings" aria-selected="false">Listings</button>
                </li>
              </ul>
              <div class="tab-content pt-2" id="myTabContent">
                <div class="tab-pane show active" id="detail" role="tabpanel" aria-labelledby="home-tab">
                <div class="card">
            <div class="card-body">
              <h5 class="card-title"><?php echo $desc; ?></h5>

              <!-- Table with stripped rows -->
              <table class="table table-striped">
                 <tbody>
                  <tr>
                    <th scope="row" width=200>ID</th>
                    <td><?php echo $id; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Date Acquired</th>
                    <td><?php echo $date_acq; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Cost</th>
                    <td><?php echo $cost; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Source</th>
                    <td><?php echo $item_source; ?></td>
                   </tr>
                    <tr>
                    <th scope="row">Brand</th>
                    <td><?php echo $brand; ?></td>
                   </tr>
                  <tr>
                    <th scope="row" width=200>Model</th>
                    <td><?php echo $model; ?></td>
                  </tr>
                  <tr>
                    <th scope="row" width=200>Size</th>
                    <td><?php echo $item_size; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Type</th>
                    <td><?php echo $type; ?></td>
                  </tr>
                    <th scope="row" width=200>Condition</th>
                    <td><?php echo $condition; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Upper Material</th>
                    <td><?php echo $upper; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Sole</th>
                    <td><?php echo $sole; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Style</th>
                    <td><?php echo $style; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Width</th>
                    <td><?php echo $width; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Color</th>
                    <td><?php echo $color; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Vintage</th>
                    <td><?php echo $vintage; ?></td>
                   </tr>
                  <tr>
                    <th scope="row">Closure</th>
                    <td><?php echo $closure; ?></td>
                  </tr>
                    <th scope="row" width=200>Category</th>
                    <td><?php echo $category; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Weight</th>
                    <td><?php echo $weight; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Comments</th>
                    <td><?php echo $comments; ?></td>
                    </tr>
                </tbody>
              </table>
              <!-- End Table with stripped rows -->

            </div>
          </div>
         </div>
       <!-- end table -->
                
                <div class="tab-pane" id="edit" role="tabpanel" aria-labelledby="edit-tab">
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
                    <input type="text" class="form-control" id="Vintage" name="Vintage" value='<?php echo $vintage; ?>' placeholder="Vintage">
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
			foreach ($src as $value) {
				echo "$value";
				}

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
                	<?php echo $update_button; ?>
                  	<button type="reset" class="btn btn-secondary">Reset</button>
                     </div>
                   </div>
                </div>
               
                
              </form><!-- End floating Labels Form -->

            </div>
                
                </div>
                <div class="tab-pane" id="listings" role="tabpanel" aria-labelledby="listings-tab">
                  <div class="card-body">
                  <div class="col-md-12">
                    <div class="text-right">
                	<?php include './includes/inventory/listing_input_modal.inc'; ?>
                     </div>
                 </div>
                 <h5 class="card-title">Item Listings</h5>

              <!-- Table with stripped rows -->
              <table class="table table-striped">
                <thead>
                  <tr>
                    <th scope="col">Listing #</th>
                    <th scope="col">Platform</th>
                    <th scope="col">Listing Date</th>
                    <th scope="col">Title</th>
                    <th scope="col">Status</th>
                  </tr>
                </thead>
                <tbody>
                <?php
                 	if (mysqli_num_rows($listings) > 0) {
				// output data of each row
	  				while($row = mysqli_fetch_assoc($listings)) {
	  					echo "<tr>";
                    				echo "<th> <a href='./inventory.php?type=listing&listing_id=" . $row['ID'] . "'>" . $row['ID'] . "</a></th>";
	  					echo "<td>" . $row['Platform_Name'] . "</td>";
	  					echo "<td>" . $row['Date_Listed'] . "</td>";
	  					echo "<td>" . $row['Listing_Title'] . "</td>";
	  					echo "<td>" . $row['Status'] . "</td>";
	  					echo "</tr>";
	  				}
	  		} else {
	  			echo "No Listings";
			}		
		?>
              
                </tbody>
              </table>
              <!-- End Table with stripped rows -->
                 
 		</div>
                </div>
              </div><!-- End Default Tabs -->

            </div>
          </div>
        </div>
        <div class="col-xl-3">

          <div class="card">
            <div class="card-body profile-card pt-4 d-flex flex-column align-items-center">

              <img src=<?php echo "'assets/img/" . $shoe_img . "'"; ?> alt="Profile" class="rounded-circle">
              <h2><?php echo $brand . " " . $model; ?></h2>
              <h3><?php echo status_to_text($mysqli, $status); ?></h3>
            </div>
          </div>
          <?php 
            if (!empty($show_detail)) {
                
                include $show_detail;
            }
          
          ?>

        </div>
        </div>
      </div>
     
    </section>

  </main><!-- End #main -->            

