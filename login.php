<?php
session_start();
require_once "./includes/dbconnect.php";
if (!$mysqli)
{
   echo 'Connection failed<br>';
   echo 'Error number: ' . mysqli_connect_errno() . '<br>';
   echo 'Error message: ' . mysqli_connect_error() . '<br>';
   die();
}

if (!empty($_POST['username'])) {

$sql = "SELECT ID FROM tbl_Auth WHERE Username = '" . $_POST['username'] . "' AND Password = '" . $_POST['password'] . "'";
$result = mysqli_query($mysqli, $sql);

if (mysqli_num_rows($result) > 0) {
  // output data of each row
  while($row = mysqli_fetch_assoc($result)) {
    echo "<BR> Success <BR>";
    echo $row["ID"];
    setcookie("FUS_AUTH", $row["ID"], time(), (86400 * 1), '/');
    header("Location: index.php");
  }
} else {
  include './includes/login.inc';
 
}
mysqli_close($conn);
} else {
   include './includes/login.inc';
}


?>
