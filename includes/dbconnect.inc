<?PHP
/* Host name of the MySQL server */
$host = 'localhost';
/* MySQL account username */  - > NEED TO USE A SECRET HERE. 
$user = 'u108093942_fus_db_user';
/* MySQL account password */ - > NEED TO USE A SECRET HERE. 
$passwd = 'Claire10';
/* The schema you want to use */
$schema = 'u108093942_db_FUS';
/* Connection with MySQLi, procedural-style */
$mysqli = mysqli_connect($host, $user, $passwd, $schema);
/* Check if the connection succeeded */

if (!$mysqli)
{
   echo 'Connection failed<br>';
   echo 'Error number: ' . mysqli_connect_errno() . '<br>';
   echo 'Error message: ' . mysqli_connect_error() . '<br>';
   die();
}
?>
