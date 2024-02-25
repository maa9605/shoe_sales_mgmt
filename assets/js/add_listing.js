$(document).ready(function(){ 	
	$("button#insert_listing").click(function(){
		$.ajax({
			type: "POST",
			url: "/includes/inventory/add_listing.php",
			data: $('form.feedback').serialize(),
			success: function(message){
				//$("#feedback").html(message);
				$("#modal_add_listing").modal('hide'); 
				//alert("Success");
			},
			error: function(){
				alert("Error");
			}
		});
	});	
});
