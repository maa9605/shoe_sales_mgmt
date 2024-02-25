<a href="./inventory.php?type=detail&item=<?php echo $row['ID']; ?>" class="list-group-item list-group-item-action">
	<div class="d-flex w-100 justify-content-between">
		<h5 class="mb-3"><B><?php echo $row['description']; ?></B></h5> <small class="text-muted"><?php echo status_to_text($mysqli, $row['status']); ?></small>
        </div>
        <div class="d-flex w-100 justify-content-between">
                <p class="mb-3">
                <B>Inv#:</B> <?php echo $row['ID']; ?> 
                <B>Brand:</B> <?php echo $row['brand']; ?> 
                <B>Cost:</B> <?php echo $row['cost']; ?> 
                <B>Size:</B> <?php echo $row['Item_Size']; ?>
                </p>
               
        </div>
        <div class="d-flex w-100 justify-content-between">
               	<p class="mb-3">
                <B>Date Acquired:</B> <?php echo $row['Date_Aquired']; ?>   
                <B>Source:</B> <?php echo $row['Source_Name']; ?>
                </p>
                
         </div>
         
</a>



