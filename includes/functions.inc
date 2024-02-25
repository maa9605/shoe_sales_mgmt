<?PHP
require_once "./includes/dbconnect.inc";

    function status_to_text($dbc, int $idx) {
       $sql = "SELECT Dict_Name from tbl_Dictionary WHERE ID=$idx";
       $status_qry = mysqli_query($dbc, $sql);
        
        while ($obj = $status_qry -> fetch_object()) { 
   	        $status_text = $obj->Dict_Name;
        }
        
        Return $status_text;
    }
?>
        
        