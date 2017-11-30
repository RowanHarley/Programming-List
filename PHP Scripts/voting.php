<html>
	<head>
		<title>Voting System</title>
	</head>
	<body>
		<center>
			<h1>This is an easy-to-use voting system</h1>
		</center>
		<script>
	
			var Select1 = document.getElementById('1st');
			var Select2 = document.getElementById('2nd');
			var Select3 = document.getElementById('3rd');
			var Final = document.getElementById('Final');
		
			function Remove1(){
				Select2.remove(Select1.selectedIndex);
				Select3.remove(Select1.selectedIndex);
				Final.remove(Select1.selectedIndex);
			}function Remove2(){
				Select1.remove(Select2.selectedIndex);
				Select3.remove(Select2.selectedIndex);
				Final.remove(Select2.selectedIndex);
			}function Remove3(){
				Select1.remove(Select3.selectedIndex);
				Select2.remove(Select3.selectedIndex);
				Final.remove(Select3.selectedIndex);
			}function Remove4(){
				Select1.remove(Final.selectedIndex);
				Select2.remove(Final.selectedIndex);
				Select3.remove(Final.selectedIndex);
			}
	
		</script>
		<?php
	//This is a voting system. You can change the code if you want
	
	//Feel Free to change the code below to suit you \/
	
	//-----------------------------------------------------------------------------------------------
	$servername = getenv('IP');
    $username = getenv('C9_USER');
    $passwordp = "Harleys12";
    $database = "users";
    $dbport = 3306;
    
    // Create connection
    $db = mysql_connect($servername, $username, $passwordp, $dbport)or die("Cant Connect to server");
    mysql_select_db($database) or die("Cant connect to database");
	//-----------------------------------------------------------------------------------------------
	
	//Simple Version
	//-----------------------------------------------------------------------------------------------
	$form = "
	<form action='.login.php' method='post'>
		<table>
			<tr>
				<td>Candidate 1</td>
				<td>This is the candidate's description</td>
			</tr>
			<tr>
				<td>Candidate 2</td>
				<td>This is the candidate's description</td>
			</tr>
			<tr>
				<td>Candidate 3</td>
				<td>This is the candidate's description</td>
			</tr>
			<tr>
				<td>Candidate 4</td>
				<td>This is the candidate's description</td>
			</tr>
			
			<tr>
				<td>1st Vote</td>
				<td>
					<select id='1st' onclick='Remove1()'>
						<option>Candidate 1</option>
						<option>Candidate 2</option>
						<option>Candidate 3</option>
						<option>Candidate 4</option>
					</select>
				</td>
			</tr>
			<tr>
				<td>2nd Vote</td>
				<td>
					<select id='2nd' onclick='Remove2()'>
						<option>Candidate 1</option>
						<option>Candidate 2</option>
						<option>Candidate 3</option>
						<option>Candidate 4</option>
					</select>
				</td>
			</tr>
			<tr>
				<td>3rd Vote</td>
				<td>
					<select id='3rd' onclick='Remove3()'>
						<option>Candidate 1</option>
						<option>Candidate 2</option>
						<option>Candidate 3</option>
						<option>Candidate 4</option>
					</select>
				</td>
			</tr>
			<tr>
				<td>Final Vote</td>
				<td>
					<select id='Final' onclick='Remove4()'>
						<option>Candidate 1</option>
						<option>Candidate 2</option>
						<option>Candidate 3</option>
						<option>Candidate 4</option>
					</select>
				</td>
			</tr>
			<tr>
				<td></td>
				<td><input type='submit' name='vote' value='Vote Now!' /></td>
			</tr>
		</table>
	</form>
	";
	
	$isPosting = true;
	//This is the time you want to post the results at
	$timeFinish = strtotime("14:00 January 10 2016");
	$timeNow = time();
	if($timeNow >= $timeFinish){
		$isPosting = false;
		
	}
	$c1 = $_POST['c1'];
	$c2 = $_POST['c2'];
	$c3 = $_POST['c3'];
	$c4 = $_POST['c4'];
	if($isPosting){
		echo $form;
		MeekMethodTallying();
	}
	
	if(isset($c1)){
		$query = "UPDATE candidates 
				  SET candidate1 = candidate1 + 1";
		$result=mysql_query($query);
		if($result){
			$isPosting = false;
			echo "<h2>Thank you for voting! The results will be posted at $timeFinish</h2>";
		}
	} else if(isset($c2)){
		$query = "UPDATE candidates 
				  SET candidate2 = candidate1 + 1";
		$result=mysql_query($query);
		if($result){
			$isPosting = false;
			echo "<h2>Thank you for voting! The results will be posted at $timeFinish</h2>";
		}
	} else if(isset($c3)){
		$query = "UPDATE candidates 
				  SET candidate1 = candidate3 + 1";
		$result=mysql_query($query);
		if($result){
			$isPosting = false;
			echo "<h2>Thank you for voting! The results will be posted at $timeFinish</h2>";
		}
	} else if(isset($c4)){
		$query = "UPDATE candidates 
				  SET candidate1 = candidate4 + 1";
		$result=mysql_query($query);
		if($result){
			$isPosting = false;
			echo "<h2>Thank you for voting! The results will be posted at $timeFinish</h2>";
		}
	}
	//-----------------------------------------------------------------------------------------------
	//Now It gets a bit more complicated. If you don't want to use this please comment it out.
	function MeekMethodTallying(){
		//How many candidates get through?
		$seats = 2;
	
		$votes = mysql_query("SELECT * FROM candidates");
		$numrows = mysql_num_rows($votes);
		$countedVotes = (int)$numrows['candidate1'] + (int)$numrows['candidate2'] + (int)$numrows['candidate3'] + (int)$numrows['candidate4'];
	
		$quota = floor((($seats + 1)\$countedVotes) + 1);
	
		if((int)$numrows['candidate1'] >= $quota){
			$votesLeft = (int)$numrows['candidate1'] - $quota;
		
			if($votesLeft > 0){
				
			}
		}else if((int)$numrows['candidate2'] >= $quota){
			$votesLeft = (int)$numrows['candidate2'] - $quota;
		
			if($votesLeft > 0){
				
			}
		}else if((int)$numrows['candidate3'] >= $quota){
			$votesLeft = (int)$numrows['candidate3'] - $quota;
		
			if($votesLeft > 0){
				
			}
		}else if((int)$numrows['candidate4'] >= $quota){
			$votesLeft = (int)$numrows['candidate4'] - $quota;
		
			if($votesLeft > 0){
				
			}
		}
	}
	
?>
		<!-- Don't forget to change the form action= to the name of this file -->
		<!--
		<form action='.login.php' method='post'>
			<table>
				<tr>
					<td>Candidate 1</td>
					<td>This is the candidate's description</td>
				</tr>
				<tr>
					<td></td>
					<td><input type='submit' name='c1' value='Vote for candidate 1!' /></td>
				</tr>
				<tr>
					<td>Candidate 2</td>
					<td>This is the candidate's description</td>
				</tr>
				<tr>
					<td></td>
					<td><input type='submit' name='c2' value='Vote for candidate 2!' /></td>
				</tr>
				<tr>
					<td>Candidate 3</td>
					<td>This is the candidate's description</td>
				</tr>
				<tr>
					<td></td>
					<td><input type='submit' name='c3' value='Vote for candidate 3!' /></td>
				</tr>
				<tr>
					<td>Candidate 4</td>
					<td>This is the candidate's description</td>
				</tr>
				<tr>
					<td></td>
					<td><input type='submit' name='c4' value='Vote for candidate 4!' /></td>
				</tr>
				<tr>
					<td><a href='./register.php'>Register Now!!!</a></td>
					<td><a href='./forgotpass.php'>Reset your password</a></td>
				</tr>
			</table>
		</form>
		-->
	</body>
</html>

