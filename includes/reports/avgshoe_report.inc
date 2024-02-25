<?php
require_once "./includes/dbconnect.inc";


$sql = "Select * from Average_Shoe_Cost";
$result = mysqli_query($mysqli, $sql);

$sources_sql = "SELECT Source_Name, COUNT(Source_Name) AS Source_Count FROM All_Inventory GROUP BY Source_Name";
$sources = mysqli_query($mysqli, $sources_sql);
while ($row = $sources->fetch_array(MYSQLI_ASSOC))
	{
		$source_name[] = "'" . $row['Source_Name'] . "'";
		$source_distro[] = $row['Source_Count'];
	}

$avg_shoe_by_source = "SELECT Source_Name, FORMAT(AVG(cost),2) AS Avg_Shoe FROM All_Inventory GROUP BY Source_Name ORDER BY AVG(cost) DESC";
$avg_shoe_source = mysqli_query($mysqli, $avg_shoe_by_source);
while ($row = $avg_shoe_source->fetch_array(MYSQLI_ASSOC))
	{
		$avg_source_name[] = "'" . $row['Source_Name'] . "'";
		$avg_source_cost[] = $row['Avg_Shoe'];
	}	



?>
<main id="main" class="main">

    <div class="pagetitle">
      <h1>Reports</h1>
      <nav>
        <ol class="breadcrumb">
          <li class="breadcrumb-item"><a href="index.php">Home</a></li>
          <li class="breadcrumb-item">Reports</li>
          <li class="breadcrumb-item active">Sourcing Report</li>
        </ol>
      </nav>
    </div><!-- End Page Title -->

    <section class="section">
      <div class="row">
      <div class="col-lg-6">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title">Item Sources</h5>

              <!-- Donut Chart -->
              <div id="donutChart"></div>

              <script>
                document.addEventListener("DOMContentLoaded", () => {
                  new ApexCharts(document.querySelector("#donutChart"), {
                    series: [<?php echo implode(",",$source_distro);?>],
                    chart: {
                      height: '600',
                      type: 'donut',
                      toolbar: {
                        show: true
                      }
                    },
                    labels: [<?php echo implode(",",$source_name);?> ],
                  }).render();
                });
              </script>
              <!-- End Donut Chart -->

            </div>
          </div>
        </div>
    
        <div class="col-lg-6">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title">Avg Shoe Cost by Source</h5>

              <!-- Bar Chart -->
              <div id="barChart"></div>

              <script>
                document.addEventListener("DOMContentLoaded", () => {
                  new ApexCharts(document.querySelector("#barChart"), {
                    series: [{
                      data: [<?php echo implode(",",$avg_source_cost);?>]
                    }],
                    chart: {
                      type: 'bar',
                      height: 350
                    },
                    plotOptions: {
                      bar: {
                        borderRadius: 4,
                        horizontal: true,
                      }
                    },
                    dataLabels: {
                      enabled: false
                    },
                    xaxis: {
                      categories: [<?php echo implode(",",$avg_source_name);?>],
                    }
                  }).render();
                });
              </script>
              <!-- End Bar Chart -->

            </div>
          </div>
        </div>

         
          
          <div class="col-lg-12">         
         <div class="card">
            <div class="card-body">
              <h5 class="card-title">Average Shoe Cost Report</h5>

              <!-- Table with stripped rows -->
              <table class="table table-striped">
                <thead>
                  <tr>
                    <th scope="col">Month</th>
                    <th scope="col">Year</th>
                    <th scope="col">Items</th>
                    <th scope="col">Average Cost</th>
                  </tr>
                </thead>
                  <tbody>
                	<?php 
                		if (mysqli_num_rows($result) > 0) {
  				// output data of each row
  					while($row = mysqli_fetch_assoc($result)) {
  						include './includes/reports/report_table.inc';
 					 }
				} else {
  				echo "0 results";
				}
			mysqli_close($mysqli);
                	?>
                 </tbody>	
                </table>	
                <!-- End Inv Table Summary -->
              </div>
             <!-- End List group Advanced Content -->

            </div>
          </div>

        </div>
        
          </div>
	</div>
   

      </div>
    </section>

  </main><!-- End #main -->
