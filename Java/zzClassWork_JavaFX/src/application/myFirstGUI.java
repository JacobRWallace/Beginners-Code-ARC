package application;
//import java.awt.Font;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

public class myFirstGUI extends Application {
    private Label mylabel;
    private Button b1;

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        launch(args);
    }
    public void start(Stage st) 
    {
        mylabel = new Label("Hi from CS-2365");
        
        //Lavel mylabel1=new Label("It is JAVAFX");
        
        b1 = new Button("CS2365");
        b1.setOnAction(new ButtonHandler());

        VBox mybox1 = new VBox(mylabel, b1);
        
        
        mybox1.setAlignment(Pos.CENTER);
        Scene myscene = new Scene(mybox1, 500, 300);
        
        st.setScene(myscene);
        
        st.setTitle("My First GUI");
        st.show();
    }

    class ButtonHandler implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            mylabel.setText("You clicked the button");
            b1.setText("Thank you");
        }
    }
}