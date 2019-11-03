import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.text.Text;
import javafx.scene.paint.Color;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.scene.canvas.Canvas;
import javafx.scene.text.*;
import javafx.scene.canvas.GraphicsContext;

public class MultiplyTable extends Application{
	public void start(Stage mainStage){
		mainStage.setTitle("Multiplication Table");

		GridPane root = new GridPane();
		Scene s = new Scene(root, 400, 400);
		Label l = new Label("Enter Number");
		TextField n = new TextField();
		Button b = new Button("Show Table");
		Canvas canvas = new Canvas(200,200);
		GraphicsContext gc = canvas.getGraphicsContext2D();

		b.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				int num = Integer.parseInt(n.getText());
				gc.clearRect(0,0,200,200);
				gc.setFont(new Font(20));
				int x=0, y=20;
				for(int i=1; i<=10; i++, y+=20){
					gc.fillText(num + "x" + i + "=" + (i*num), x, y);
				}
			}
		});

		root.addRow(0, l, n);
		root.addRow(1, b);
		root.add(canvas, 0, 3);
		mainStage.setScene(s);
		mainStage.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}