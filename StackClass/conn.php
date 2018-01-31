<?php
$host="localhost";
$user="z1818371";
$password="NIU.1994May21";
$db="z1818371";
try{
	$conn=new PDO("mysql:host=$host;dbname=$db",$user,$password);
	$conn->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
	echo "Connected successfully"; 
    }
catch(PDOException $e)
    {
    echo "ERROR: " . $e->getMessage();
	}
?>