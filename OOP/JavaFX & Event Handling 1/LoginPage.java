import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.scene.text.*;

public class LoginPage extends Application{
	public void start(Stage mainStage){
		mainStage.setTitle("Welcome");
		GridPane grid = new GridPane();
		Label l1 = new Label("Welcome");
		Label l2 = new Label("User Name");
		TextField user = new TextField();
		Label l3 = new Label("Password");
		TextField psw = new TextField();
		Button b = new Button("Sign In");
		Canvas canvas = new Canvas(500,1000);
		GraphicsContext gc = canvas.getGraphicsContext2D();

		b.setOnAction( new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				gc.clearRect(0,0,100,1000);
				gc.setFont(new Font(20));
				gc.fillText("Welcome " + psw.getText(), 10, 100);
			}
		});

		grid.addRow(0, l1);
		grid.addRow(1, l2, user);
		grid.addRow(2, l3, psw);
		grid.addRow(3, b);
		grid.add(canvas, 0, 4);

		Scene s = new Scene(grid, 800, 800);
		mainStage.setScene(s);
		mainStage.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}