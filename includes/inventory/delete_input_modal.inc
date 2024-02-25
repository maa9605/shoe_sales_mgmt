	<button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target='#modal_delete_<?php echo $id; ?>'>Delete This Item</button>
             <div class="modal" data-bs-backdrop="false" id='modal_delete_<?php echo $id; ?>' tabindex="-1">
                <div class="modal-dialog modal-dialog-centered">
                  <div class="modal-content">
                    <div class="modal-header">
                      <h3 class="modal-title">Deletion Confirmation</h3>
                      <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    		
                    		
                    		<div class="modal-body">
                    			Do you really want to delete this Item?
				</div>
                    
                    <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancel</button>
                      <a class="btn btn-success" href=".\inventory.php?type=delete&item_id=<?php echo $id; ?>" role="button">Yes, Delete This Item</a>
               
                    </div>
                  </div>
                </div>
              </div><!-- End Small Modal-->
