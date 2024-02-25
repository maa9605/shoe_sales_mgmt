<?php
//get monthly sales number
$this_month = date("F");

require_once "./includes/dbconnect.inc";

//This Months Sales
$sql = "Select * from Monthly_Gross WHERE Sales_Month ='" . $this_month . "'";
$this_month_result = mysqli_query($mysqli, $sql);

while ($obj = $this_month_result -> fetch_object()) { 
   	$items_sold = $obj->Items_Sold;
   	$sales_year = $obj->Sale_Year;
   	$sales_month = $obj->Sales_Month;
   	$revenue = $obj->Revenue;
   	$cogs = $obj->COGS;
   	$shipping = $obj->Shipping;
   	$platform_fees = $obj->Svc_Fees;
   	$gross = $obj->Gross_Sales;
	}
	
if ($items_sold != 0) {
	$avg_sale = $revenue/$items_sold;
	$avg_sale = "$" . number_format($avg_sale,2);
	$profit = number_format((100* (1-(($revenue - (int) $gross) / $revenue))),2);
	}
else {
	$avg_sale = "$0.00";
	$profit = "0";
	}

//Most Recent Sales
$rssql = "SELECT * from Last_10_Sales LIMIT 10";
$last_10 = mysqli_query($mysqli, $rssql);

//Sales By Month 
$assql = "SELECT Sales_Month, Revenue, Gross_Sales from Monthly_Gross";
$sales_by_month = mysqli_query($mysqli, $assql);
while ($row = $sales_by_month->fetch_array(MYSQLI_ASSOC))
	{
		$months[] = "'" . $row['Sales_Month'] . "'";
		$monthly_rev[] = $row['Revenue'];
		$monthly_gross[] = $row['Gross_Sales'];
	}

//sales by platform
$sbpsql = "SELECT * from Sales_by_Platform";
$sales_by_platform = mysqli_query($mysqli, $sbpsql);
while ($row = $sales_by_platform->fetch_array(MYSQLI_ASSOC))
	{
		$platforms[] = "{value: " . $row['Sales'] . ", name: '" . $row['Platform'] . "'}";
	}
	
//Key Indicators
$this_year = date("Y");
$kpisql = "CALL yearly_kpi('" . $this_year . "')";
$kpi_ytd = mysqli_query($mysqli, $kpisql);
while ($obj = $kpi_ytd -> fetch_object()) { 
   	$kpi_totalsales = $obj->TotalSales;
   	$kpi_avgsale = $obj->AvgSale;
   	$kpi_avgcost = $obj->AvgCost;
   	$kpi_avggross = $obj->AvgGross;
	}

?>
<main id="main" class="main">

    <div class="pagetitle">
      <h1>Dashboard</h1>
      <nav>
        <ol class="breadcrumb">
          <li class="breadcrumb-item"><a href="index.html">Home</a></li>
          <li class="breadcrumb-item active">Dashboard</li>
        </ol>
      </nav>
    </div><!-- End Page Title -->

    <section class="section dashboard">
      <div class="row">

        <!-- Left side columns -->
        <div class="col-lg-8">
          <div class="row">

            <!-- Sales Card -->
            <div class="col-xxl-4 col-md-4">
              <div class="card info-card sales-card">

                <div class="card-body">
                  <h5 class="card-title">Sales <span>| This Month</span></h5>

                  <div class="d-flex align-items-center">
                    <div class="card-icon rounded-circle d-flex align-items-center justify-content-center">
                      <i class="bi bi-cart"></i>
                    </div>
                    <div class="ps-3">
                      <h6><?php echo $items_sold; ?></h6>
                      <span class="text-success small pt-1 fw-bold"><?php $avg_daily = $items_sold / date("d"); echo number_format($avg_daily,2) ?></span> <span class="text-muted small pt-2 ps-1">sales per day</span>
                    </div>
                  </div>
                </div>

              </div>
            </div><!-- End Sales Card -->

            <!-- Revenue Card -->
            <div class="col-xxl-4 col-md-4">
              <div class="card info-card revenue-card">
                <div class="card-body">
                  <h5 class="card-title">Revenue <span>| This Month</span></h5>

                  <div class="d-flex align-items-center">
                    <div class="card-icon rounded-circle d-flex align-items-center justify-content-center">
                      <i class="bi bi-currency-dollar"></i>
                    </div>
                    <div class="ps-3">
                      <h6><?php echo $revenue ?></h6>
                      <span class="text-success small pt-1 fw-bold"><?php echo $avg_sale; ?></span> <span class="text-muted small pt-2 ps-1">per sale</span>
                   </div>
                  </div>
                </div>

              </div>
            </div><!-- End Revenue Card -->

            <!-- Customers Card -->
            <div class="col-xxl-4 col-md-4">

              <div class="card info-card customers-card">
                <div class="card-body">
                  <h5 class="card-title">Gross Sales <span>| This Month</span></h5>

                  <div class="d-flex align-items-center">
                    <div class="card-icon rounded-circle d-flex align-items-center justify-content-center">
                      <i class="bi bi-people"></i>
                    </div>
                    <div class="ps-3">
                      <h6><?php echo $gross ?></h6>
                      <span class="text-success small pt-1 fw-bold"><?php echo $profit . "%"; ?></span>
                    </div>
                  </div>

                </div>
              </div>

            </div><!-- End Customers Card -->

            <!-- Reports -->
            <div class="col-12">
              <div class="card">

                <div class="filter">
                  <a class="icon" href="#" data-bs-toggle="dropdown"><i class="bi bi-three-dots"></i></a>
                  <ul class="dropdown-menu dropdown-menu-end dropdown-menu-arrow">
                    <li class="dropdown-header text-start">
                      <h6>Filter</h6>
                    </li>

                    <li><a class="dropdown-item" href="#">Today</a></li>
                    <li><a class="dropdown-item" href="#">This Month</a></li>
                    <li><a class="dropdown-item" href="#">This Year</a></li>
                  </ul>
                </div>
	   <div class="card">
            <div class="card-body">
              <h5 class="card-title">Monthly Sales and Gross Profit</h5>

              <!-- Column Chart -->
              <div id="columnChart"></div>

              <script>
                document.addEventListener("DOMContentLoaded", () => {
                  new ApexCharts(document.querySelector("#columnChart"), {
                    series: [{
                      name: 'Gross Profit',
                      data: [<?php echo implode(",",$monthly_gross);?>]
                    }, {
                      name: 'Revenue',
                      data: [<?php echo implode(",",$monthly_rev);?>]
                    }],
                    chart: {
                      type: 'bar',
                      height: 350
                    },
                    plotOptions: {
                      bar: {
                        horizontal: false,
                        columnWidth: '55%',
                        endingShape: 'rounded'
                      },
                    },
                    dataLabels: {
                      enabled: false
                    },
                    stroke: {
                      show: true,
                      width: 2,
                      colors: ['transparent']
                    },
                    xaxis: {
                      categories: [<?php echo implode(",",$months);?>],
                    },
                    yaxis: {
                      title: {
                        text: '$ (thousands)'
                      }
                    },
                    fill: {
                      opacity: 1
                    },
                    tooltip: {
                      y: {
                        formatter: function(val) {
                          return val
                        }
                      }
                    }
                  }).render();
                });
              </script>
              <!-- End Column Chart -->
	 </div>
        </div>

              </div>
            </div><!-- End Reports -->

            <!-- Recent Sales -->
            <div class="col-12">
              <div class="card recent-sales overflow-auto">

                <div class="card-body">
                  <h5 class="card-title">Recent Sales <span>| Last 10 Sales</span></h5>

                  <table class="table table-borderless datatable">
                    <thead>
                      <tr>
                        <th width="75" scope="col">Date Sold</th>
                        <th width="400" scope="col">Item</th>
                        <th width="75" scope="col">Sale Price</th>
                        <th width="75" scope="col">Cost</th>
                        <th width="75" scope="col">Net</th>
                      </tr>
                    </thead>
                    <tbody>
                    	<?php 
                		if (mysqli_num_rows($last_10) > 0) {
  				// output data of each row
  					while($row = mysqli_fetch_assoc($last_10)) {
  						include './includes/reports/last_10_lines.inc';
 					 }
				} else {
  				echo "0 results";
				}
			mysqli_close($mysqli);
                	?>
                      
                    </tbody>
                  </table>

                </div>

              </div>
            </div><!-- End Recent Sales -->


          </div>
        </div><!-- End Left side columns -->

        <!-- Right side columns -->
        <div class="col-lg-4">

          <!-- Recent Activity -->
          <div class="card">
            <div class="filter">
              <a class="icon" href="#" data-bs-toggle="dropdown"><i class="bi bi-three-dots"></i></a>
              <ul class="dropdown-menu dropdown-menu-end dropdown-menu-arrow">
                <li class="dropdown-header text-start">
                  <h6>Filter</h6>
                </li>

                <li><a class="dropdown-item" href="#">Today</a></li>
                <li><a class="dropdown-item" href="#">This Month</a></li>
                <li><a class="dropdown-item" href="#">This Year</a></li>
              </ul>
            </div>

            <div class="card-body">
              <h5 class="card-title">Key Indicators <span>| Year To Date</span></h5>

              <div class="activity">

                <div class="activity-item d-flex">
                  <div class="activite-label">Sales</div>
                  <i class='bi bi-circle-fill activity-badge text-success align-self-start'></i>
                  <div class="activity-content">
                    <?php echo $kpi_totalsales; ?>
                  </div>
                </div><!-- End activity item-->
                
                <div class="activity-item d-flex">
                  <div class="activite-label">Avg Sale</div>
                  <i class='bi bi-circle-fill activity-badge text-success align-self-start'></i>
                  <div class="activity-content">
                    <?php echo $kpi_avgsale; ?>
                  </div>
                </div><!-- End activity item-->
                
                 <div class="activity-item d-flex">
                  <div class="activite-label">Avg Cost</div>
                  <i class='bi bi-circle-fill activity-badge text-success align-self-start'></i>
                  <div class="activity-content">
                    <?php echo $kpi_avgcost; ?>
                  </div>
                </div><!-- End activity item-->
                
                  <div class="activity-item d-flex">
                  <div class="activite-label">Avg Gross</div>
                  <i class='bi bi-circle-fill activity-badge text-success align-self-start'></i>
                  <div class="activity-content">
                    <?php echo $kpi_avggross; ?>
                  </div>
                </div><!-- End activity item-->

              </div>

            </div>
          </div><!-- End Recent Activity -->


          <!-- Website Traffic -->
          <div class="card">
            <div class="filter">
              <a class="icon" href="#" data-bs-toggle="dropdown"><i class="bi bi-three-dots"></i></a>
              <ul class="dropdown-menu dropdown-menu-end dropdown-menu-arrow">
                <li class="dropdown-header text-start">
                  <h6>Filter</h6>
                </li>

                <li><a class="dropdown-item" href="#">Today</a></li>
                <li><a class="dropdown-item" href="#">This Month</a></li>
                <li><a class="dropdown-item" href="#">This Year</a></li>
              </ul>
            </div>

            <div class="card-body pb-0">
              <h5 class="card-title">Sales By Platform <span>| All</span></h5>

              <div id="trafficChart" style="min-height: 400px;" class="echart"></div>

              <script>
                document.addEventListener("DOMContentLoaded", () => {
                  echarts.init(document.querySelector("#trafficChart")).setOption({
                    tooltip: {
                      trigger: 'item'
                    },
                    legend: {
                      top: '5%',
                      left: 'center'
                    },
                    series: [{
                      name: 'Access From',
                      type: 'pie',
                      radius: ['40%', '70%'],
                      avoidLabelOverlap: false,
                      label: {
                        show: false,
                        position: 'center'
                      },
                      emphasis: {
                        label: {
                          show: true,
                          fontSize: '18',
                          fontWeight: 'bold'
                        }
                      },
                      labelLine: {
                        show: false
                      },
                      data: [<?php echo implode(",",$platforms); ?>]
                    }]
                  });
                });
              </script>

            </div>
          </div><!-- End Website Traffic -->

        

        </div><!-- End Right side columns -->

      </div>
    </section>

  </main>
