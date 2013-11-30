<?php
mb_http_input("utf-8");
mb_http_output("utf-8");

// Connect to the database
$conn = pg_connect("user=postgres password=12345 dbname=postgres hostaddr=127.0.0.1 port=5432");
?>

<?php
function getAllDataTimeCLP()
{
    global $conn;
    // Retrieve all values of column time from the CLP database
    $result = pg_query($conn, "SELECT * FROM CLP");
    
    return $result;
}

function retrieveData($datetime = 0 , $datetime2 = 0)
{
	global $conn;
	
	// Retrieve data from the CLP database
	$result = pg_query($conn, "SELECT * FROM CLP WHERE pkey BETWEEN ".$datetime." AND ".$datetime2);
	
	while ($row = pg_fetch_assoc($result)) {
		echo "<tr><td>".$row['pkey']."</td>";
		if(isset($_POST['R'])){ echo "<td>".$row['r']."</td>"; }
		if(isset($_POST['M'])){ echo "<td>".$row['m']."</td>"; }
		if(isset($_POST['D'])){ echo "<td>".$row['d']."</td>"; }
		echo "<td>".$row['time']."</td></tr>";
		}
	}
?>

<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Relatorio de Dados do CLP</title>
</head>

<body>
    <hgroup>
    
    <h1>FEMEC 42082: Redes Industriais<br>Relatório de dados gravados do CLP</h1>
    <h2>Carlos Eduardo Fanti<br>René Octavio Queiroz Dias</h2>
    
    <hr/>
    
    <form id="form1" name="form1" method="post">
    <p>
        Intervalo de tempo a ser pesquisado:</br>
        <label for="datetime">Começo:</label>
        <select name="datetime" id="datetime">
        
        <?php 
        $result=getAllDataTimeCLP();
        while ($row = pg_fetch_assoc($result)) 
        {
            if($row['pkey']==$_POST["datetime"])
            {
                echo "<option value=".$row['pkey']." selected>".$row['time']."</option>";
            }
            else
            {
                echo "<option value=".$row['pkey'].">".$row['time']."</option>";
            }
        }
        ?>
        
        </select>
        </br>
        <label for="datetime2">Fim:</label>
        <select name="datetime2" id="datetime2">
        
        <?php 
        $result=getAllDataTimeCLP();
        while ($row = pg_fetch_assoc($result)) 
        {
            if($row['pkey']==$_POST["datetime2"])
            {
                echo "<option value=".$row['pkey']." selected>".$row['time']."</option>";
            }
            else
            {
                echo "<option value=".$row['pkey'].">".$row['time']."</option>"; 
            }
        }
        ?>
        
        </select>
    </p>
    
    <p>
        Marque o parametro que deseja visualizar: </br>
        <input type="checkbox" name="R" id="R" value="1" <?php if(isset($_POST['R'])) echo 'checked="checked"'; ?> > R
        <input type="checkbox" name="M" id="M" value="1" <?php if(isset($_POST['M'])) echo 'checked="checked"'; ?> > M
        <input type="checkbox" name="D" id="D" value="1" <?php if(isset($_POST['D'])) echo 'checked="checked"'; ?> > D
    </p>
    
    <p>
        <input type="submit" name="submit" id="submit" value="OK" style=" width : 100px;">
    </p>
    
    </form>
    
<hr />

	<?php
	if(!empty($_POST))
	{
		echo '<table border="1">';
		echo '<tr>';
		
		echo '<th scope="col">Chave</th>'; 
		if(isset($_POST['R'])){ echo '<th scope="col">R</th>'; }
		if(isset($_POST['M'])){ echo '<th scope="col">M</th>'; }
		if(isset($_POST['D'])){ echo '<th scope="col">D</th>'; }
		echo '<th scope="col">Tempo</th>'; 
		
		echo '</tr>';
		retrieveData($_POST["datetime"],$_POST["datetime2"]);
		echo'</table>';
	}
	?>
	
	</hgroup>
</body>
</html>