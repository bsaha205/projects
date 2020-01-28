package ai.pkg3;

import ai.pkg3.Agent;
import java.util.Scanner;

public class Solver {

    /*
	 * The starting point of the game.
	 * Instantiates two agents (human/ minimax/ alpha beta pruning/ or other) and pass them to a game object.
	 * Here a TickTackToe game is implemented as an example. You need to extend the abstract class Game to create your own game.
	 * */
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose what you want to play");
        System.out.println("1: Human vs Cimputer");
        System.out.println("2: Computer vs Cimputer");

        int number = scanner.nextInt();
        if (number == 2) {
            Agent machine1 = new MinimaxCheckerAgent("Machine-1");
            Agent machine2 = new MinimaxCheckerAgent("Machine-2");
            Game game = new Checker_rules(machine1, machine2);
            game.play();
        } else {
            Agent machine = new MinimaxCheckerAgent("Machine");
            Agent human = new HumanCheckerAgent("Human");

            Game game = new Checker_rules(human, machine);
            game.play();
        }
        

    }

}
