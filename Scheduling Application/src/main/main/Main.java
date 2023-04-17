package com.example.jfx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.TimeZone;

public class Main extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("loginScreen.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setTitle("C195");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        //TimeZone.setDefault(TimeZone.getTimeZone("<system-time-zone>"));
        JDBC.makeConnection();
        launch(args);
        JDBC.closeConnection();

    }
}