package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class LatinTranslator extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create a Label to display the translation
        Label translationLabel = new Label("Click a button to see the translation");

        // Create Buttons for each Latin word
        Button sinisterButton = new Button("sinister");
        Button dexterButton = new Button("dexter");
        Button mediumButton = new Button("medium");

        // Set up Button actions
        sinisterButton.setOnAction(e -> translationLabel.setText("Left"));
        dexterButton.setOnAction(e -> translationLabel.setText("Right"));
        mediumButton.setOnAction(e -> translationLabel.setText("Center"));

        // Create a layout and add components
        VBox layout = new VBox(10);
        layout.getChildren().addAll(sinisterButton, dexterButton, mediumButton, translationLabel);

        // Create the Scene and set it in the Stage
        Scene scene = new Scene(layout, 300, 200);
        primaryStage.setTitle("Latin Translator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}