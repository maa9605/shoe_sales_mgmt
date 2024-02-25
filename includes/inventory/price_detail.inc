<style>
span.profit {color: #33cc33;}
span.loss {color: #F00;}
</style>
<?php 
$sql = "SELECT Cost FROM tbl_Items WHERE ID=" . $id;
$item_details = mysqli_query($mysqli, $sql);

while ($obj = $item_details -> fetch_object()) { 
   	$cost = $obj->Cost;
	}

$target = $cost * 3;
$base = $cost / .8;

?>

  <div class="card info-card customers-card">
                <div class="card-body">
                  <h5 class="card-title">Pricing <span>| Details</span></h5>
                  <div class="d-flex align-items-center">
                    <div class="ps-4">
                      <h6><b>Target Price:</b> $<?php echo number_format($target,2); ?></h6>
                      <h6><b>Liquidation Price:</b> $<?php echo number_format($base,2); ?></h6>
                      <h6><b>Item Cost:</b> $<?php echo number_format($cost,2); ?></h6>
                    </div>
                  </div>

                </div>
              </div>
