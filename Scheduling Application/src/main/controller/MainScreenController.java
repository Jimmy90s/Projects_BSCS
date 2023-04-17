package controller;


import com.example.jfx.Main;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Main screen class, a navigation menu to go to Appointments, Customers, and Reports.
 */

public class MainScreenController  {

    @FXML private Button mainMenuAppointmentClick;
    @FXML private Button mainMenuCustomerClick;
    @FXML private Button mainMenuExitClick;
    @FXML private Button mainMenuReportsClick;

    /**
     * Go to appointments main menu.
     * @param event
     * @throws IOException
     */
    @FXML
    void mainMenuAppointmentClick(ActionEvent event) throws IOException {

        Parent appointmentMenu = FXMLLoader.load(Main.class.getResource("appointments.fxml"));
        Scene scene = new Scene(appointmentMenu);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(scene);
        window.show();
    }

    /**
     * Go to customers main menu.
     * @param event
     * @throws IOException
     */
    @FXML
    void mainMenuCustomerClick(ActionEvent event) throws IOException {

        Parent customerMenu = FXMLLoader.load(Main.class.getResource("customer.fxml"));
        Scene scene = new Scene(customerMenu);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(scene);
        window.show();
    }

    /**
     * Go to reports main menu.
     * @param event
     * @throws IOException
     */
    @FXML
    void mainMenuReportsClick(ActionEvent event) throws IOException {

        Parent reportMenu = FXMLLoader.load(Main.class.getResource("reports.fxml"));
        Scene scene = new Scene(reportMenu);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(scene);
        window.show();
    }

    /**
     * Exit the program.
     * @param ExitButton
     */
    public void mainMenuExitClick(ActionEvent ExitButton) {
        System.exit(0);
    }

}