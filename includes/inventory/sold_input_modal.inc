<button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target='#modal_<?php echo $row['ID']; ?>'>
                Mark as Sold
              </button>

              <div class="modal" data-bs-backdrop="false" id='modal_<?php echo $row['ID']; ?>' tabindex="-1">
                <div class="modal-dialog modal-dialog-centered">
                  <div class="modal-content">
                    <div class="modal-header">
                      <h5 class="modal-title"><?php echo $row['description']; ?></h5>
                      <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    
                      <form class="feedback" name="feedback">
				<div class="modal-body">				
					<div class="form-group">
						<label for="name">Name</label>
						<input type="text" name="name" class="form-control">
					</div>
				
				</div>
                    
                    <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
                      <button id='submit_<?php echo $row['ID']; ?>' class="btn btn-primary">Save changes</button>
                    </div>
                  </div>
                </div>
              </div><!-- End Small Modal-->
