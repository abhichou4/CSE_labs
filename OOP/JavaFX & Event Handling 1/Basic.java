import java.util.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.geometry.Pos;
import javafx.scene.layout.*;

public class Basic extends Application{
	public void start(Stage mainStage){
		mainStage.setTitle("JavaFX");
		FlowPane root = new FlowPane();
		root.setHgap(1000);
		root.setVgap(1000);
		Scene s = new Scene(root, 500, 200);
		Label l = new Label();
		l.setAlignment(Pos.CENTER);
		l.setText("Welcome to JavaFX");
		l.setTextFill(Color.MAGENTA);
		root.getChildren().addAll(l);
		mainStage.setScene(s);
		mainStage.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}