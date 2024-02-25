<!DOCTYPE html>
<html lang="en">
  <!-- ======= Head ======= -->
  	<?php include './includes/head.inc'; ?>
  <!-- ======= Head ======= -->
<body>
  <!-- ======= Header ======= -->
  	<?php include './includes/header.inc'; ?>
  <!-- ======= Header ======= -->

  <!-- ======= Sidebar ======= -->
  	<?php include './includes/sidebar.inc'; ?>
  <!-- End Sidebar-->
  
  <!-- ======= Main ======= -->
  	<?php include './includes/inventory/' . $_GET['type'] . '_inventory.inc'; ?>
  <!-- End #main -->

 <!-- ======= Footer ======= -->
 	<?php include './includes/footer.inc'; ?>
 <!-- End Footer -->

</body>

</html>
