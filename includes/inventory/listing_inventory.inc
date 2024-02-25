<?php
require_once "./includes/dbconnect.inc";

$isql = "SELECT * FROM All_Listings WHERE ID=" . $_GET['listing_id'];

$r = mysqli_query($mysqli, $isql);

while ($obj = $r -> fetch_object()) { 
   	$id = $obj->ID;
   	$platform = $obj->Platform_Name;
   	$listing_date = $obj->Date_Listed;
   	$price = $obj->List_Price;
   	$item_id = $obj->Item_ID;
   	$title = $obj->Listing_Title;
   	$desc = $obj->Listing_Description;
   	$status = $obj->Status;
	}
/*
if ($status <> 'SOLD') {
	$update_button = "<button type='submit' class='btn btn-primary'>Update</button>";
} 
else {
	$update_button =  "<button type='submit' class='btn btn-primary disabled'>Update</button>";
}
*/
?>  

 <main id="main" class="main">

    <div class="pagetitle">
      <h1>Listing Detail</h1>
      <nav>
        <ol class="breadcrumb">
          <li class="breadcrumb-item"><a href="index.html">Home</a></li>
          <li class="breadcrumb-item">Inventory</li>
          <li class="breadcrumb-item active">Listing Detail</li>
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
                  <button class="nav-link" id="sold-tab" data-bs-toggle="tab" data-bs-target="#sold" type="button" role="tab" aria-controls="sold" aria-selected="false">Mark As Sold</button>
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
                    <th scope="row" width=200>Listing ID</th>
                    <td><?php echo $id; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Platform</th>
                    <td><?php echo $platform; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Listing Date</th>
                    <td><?php echo $listing_date; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Price</th>
                    <td><?php echo $listing_price; ?></td>
                   </tr>
                  <tr>
                    <th scope="row">Item ID</th>
                    <td><?php echo $item_id; ?></td>
                  </tr>
                    <th scope="row" width=200>Listing Title</th>
                    <td><?php echo $title; ?></td>
                  </tr>
                  <tr>
                    <th scope="row">Listing Description</th>
                    <td><?php echo $desc; ?></td>
                    </tr>
                  <tr>
                    <th scope="row">Status</th>
                    <td><?php echo $status; ?></td>
                    </tr>
                </tbody>
              </table>
              <!-- End Table with stripped rows -->

            </div>
          </div>
           <div class="col-md-6">
         <div class="text-left">
                   
         <?php include './includes/inventory/delete_listing_modal.inc'; ?>

         </div>
         </div>
         </div>
        

       <!-- end table -->
                
                <div class="tab-pane" id="sold" role="tabpanel" aria-labelledby="sold-tab">
                <div class="card-body">
              <h5 class="card-title">Mark as Sold <u><?php echo $id; ?></u></h5>

              <!-- Floating Labels Form -->
              <form method="post" action="inventory.php?type=sold" class="row g-3">
              	<!-- Begin form -->
              	<input type="hidden" id="listing_id" name="listing_id" value='<?php echo $id; ?>'>
              	<input type="hidden" id="item_id" name="item_id" value='<?php echo $item_id; ?>'>
              	<input type="hidden" id="customer_id" name="customer_id" value=1>
                 <div class="col-md-6">
                  <div class="form-floating">
                    <input type="date" class="form-control" id="date_sold" name="date_sold" vplaceholder="Date Sold">
                    <label for="date_sold">Date Sold</label>
                  </div>
                </div>
                 <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="sales_price" name="sales_price" placeholder="sales_price">
                    <label for="sales_price">Sales Price</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="shipping_cost" name="shipping_cost" placeholder="shipping_cost">
                    <label for="shipping_cost">Shipping Cost</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="platform_fee" name="platform_fee" placeholder="platform_fee">
                    <label for="platform_fee">Platform Fee</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="ad_fee" name="ad_fee" placeholder="ad_fee">
                    <label for="ad_fee">Ad Fee</label>
                  </div>
                </div>
                <div class="col-md-6">
                  <div class="form-floating">
                    <input type="text" class="form-control" id="tracking_no" name="tracking_no" placeholder="tracking_no">
                    <label for="tracking_no">Tracking Number</label>
                  </div>
                </div>
                <div class="col-md-12">
                   <div class="text-left">
                     <div class="text-right">
                	<button type="submit" class="btn btn-primary">Mark as Sold</button>
                  	<button type="reset" class="btn btn-secondary">Reset</button>
                     </div>
                   </div>
                </div>
               
                
              </form><!-- End floating Labels Form -->

            </div>
                
                </div>
                
              </div><!-- End Default Tabs -->

            </div>
          </div>
        </div>
        <div class="col-xl-3">

          <div class="card">
            <div class="card-body profile-card pt-4 d-flex flex-column align-items-center">

              <img src="assets/img/green_shoe.jpg" alt="Profile" class="rounded-circle">
              <h2><?php echo $brand . " " . $model; ?></h2>
              <h3><?php echo $status; ?></h3>
            </div>
          </div>

        </div>
        </div>
      </div>
     
    </section>

  </main><!-- End #main -->            

