package application;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.scene.control.TextField;

public class kilometerToMile extends Application {

    private Label mylabel;
    private TextField ktom;

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        launch(args);
        
    }
    public void start(Stage st) 
    {
        mylabel = new Label("Give an input to kilometer");
        ktom = new TextField();

        Button b1 = new Button("Convert");
        b1.setOnAction(new convert());

        VBox mybox1 = new VBox(mylabel, ktom, b1);
        
        mybox1.setAlignment(Pos.CENTER);
        Scene myscene = new Scene(mybox1, 500, 300);

        st.setScene(myscene);
        
        st.setTitle("My First GUI");
        st.show();
    }

    class convert implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            Double km = Double.parseDouble(ktom.getText());
            Double miles = 0.62 * km;
            mylabel.setText(String.format("%.2f miles", miles));
        }
    }
}