<tr>
	<th scope="row"><?php $sold_date = date_create($row['Date_Sold']); echo date_format($sold_date, 'M-d'); ?></th>
		<td><a href="./inventory.php?type=detail&item=<?php echo $row['Item_ID']; ?>" class="text-primary"><?php echo $row['Listing_Title']; ?></a></td>
		<td><?php echo number_format($row['Sale_Price'],2); ?></td>
                <td><?php echo number_format($row['Cost'],2); ?></td>
            	<td><?php echo number_format($row['Net'],2); ?></td>
            
</tr>
                
