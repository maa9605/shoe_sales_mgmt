	  <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target='#modal_add_listing'>
                Add Listing
              </button>

              <div class="modal" data-bs-backdrop="false" id='modal_add_listing' tabindex="-1">
                <div class="modal-dialog modal-dialog-centered">
                  <div class="modal-content">
                    <div class="modal-header">
                      <h5 class="modal-title"><b>Add Listing:</b> <?php echo $desc; ?></h5>
                      <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    
                      <form action="inventory.php?type=add_listing" method="POST">
				<div class="modal-body">				
					<div class="form-group">
						<input type="hidden" name="item_id" value='<?php echo $id; ?>' class="form-control">
						<input type="hidden" name="desc" value='<?php echo $desc; ?>' class="form-control">
						 <div class="row mb-6">
                  					<label class="col-sm-3 col-form-label">Platform</label>
                  					<div class="col-sm-4">
                    					<select class="form-select" name="platform">
                      						<option value='1' selected>Ebay</option>
                      						<option value='2'>Depop</option>
                     						<option value='3'>Poshmark</option>
                      						<option value='4'>Mercari</option>
                    					</select>
                  					</div>
                				</div>
						<div class="row mb-3">
                  					<label for="inputText" class="col-sm-3 col-form-label">List Price</label>
                  					<div class="col-sm-4">
                    					<input type="text" name="list_price" class="form-control">
                  					</div>
                				</div>
					</div>
				<div id="result">
				</div>
				
				</div>
                    
                    <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                      <button type="submit" class="btn btn-primary">Save changes</button>
                    </div>
                  </div>
                </div>
              </div><!-- End Small Modal-->
