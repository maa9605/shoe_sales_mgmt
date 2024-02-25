<style>
span.profit {color: #33cc33;}
span.loss {color: #F00;}
</style>
<?php 
$sql = "SELECT * FROM All_Sold WHERE ID=" . $id;
$sold_details = mysqli_query($mysqli, $sql);

while ($obj = $sold_details -> fetch_object()) { 
   	$sold_item_id = $obj->ID;
   	$date_sold = $obj->Date_Sold;
   	$sale_price = $obj->Sale_Price;
   	$shipping = $obj->Shipping_Cost;
   	$platform_fee = $obj->Platform_Fees;
   	$cost = $obj->Cost;
	}

$net = $sale_price - ($cost + $shipping + $platform_fee);
$style = ($net > 0) ? 'profit' : 'loss';

?>

  <div class="card info-card customers-card">
                <div class="card-body">
                  <h5 class="card-title">Sale <span>| Details</span></h5>
                  <div class="d-flex align-items-center">
                    <div class="ps-4">
                      <h6><b>Sales Date:</b> <?php echo $date_sold; ?></h6>
                      <h6><b>Sales Price:</b> $<?php echo number_format($sale_price,2); ?></h6>
                      <h6><b>Item Cost:</b> $<?php echo number_format($cost,2); ?></h6>
                      <h6><b>Shipping Cost:</b> $<?php echo number_format($shipping,2); ?></h6>
                      <h6><b>Platform Fee:</b> $<?php echo number_format($platform_fee,2); ?></h6>
                      <h5><span class="<?php echo $style;?>"><b>Net:</b> $<?php echo number_format($net,2); ?></h5>
                    </div>
                  </div>

                </div>
              </div>

