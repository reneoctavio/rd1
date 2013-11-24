<?php
mb_http_input("utf-8");
mb_http_output("utf-8");

// Connect to the database
$conn = pg_connect("user=postgres password=12345 dbname=postgres hostaddr=127.0.0.1 port=5432");
?>

<?php

function retrieveAllData()
{
	global $conn;
	// Retrieve all data from the CLP database
	$result = pg_query($conn, "SELECT * FROM CLP");
	
	while ($row = pg_fetch_assoc($result)) {
		echo "<tr>";
		echo "<td>";
		echo $row['pkey'];
		echo "</td>";
		echo "<td>";
		echo $row['r'];
		echo "</td>";
		echo "<td>";
		echo $row['m'];
		echo "</td>";
		echo "<td>";
		echo $row['d'];
		echo "</td>";
		echo "<td>";
		echo $row['time'];
		echo "</td>";
		echo "</tr>";
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
<hgroup><h1>FEMEC 42082: Redes Industriais<br>
  Relatório de dados gravados do CLP
</h1>
  <h2>Carlos Eduardo Fanti<br>
    René Octavio Queiroz Dias
  </h2>
  <form id="form1" name="form1" method="post">
    <p>Intervalo de tempo a ser pesquisado:
</p>
    <p>
      <label for="datetime">Começo:</label>
      <input type="datetime" name="datetime" id="datetime">
      <br>
      <label for="datetime2">Fim:</label>
      <input type="datetime" name="datetime2" id="datetime2">
    </p>
    <p>
      <input type="submit" name="submit" id="submit" value="OK">
    </p>
  </form>
<table border="1">
  <tr>
    <th scope="col">Chave</th>
    <th scope="col">R</th>
    <th scope="col">M</th>
    <th scope="col">D</th>
    <th scope="col">Tempo</th>
  </tr>
  <?php retrieveAllData(); ?>
</table>
</hgroup>
</body>
</html>