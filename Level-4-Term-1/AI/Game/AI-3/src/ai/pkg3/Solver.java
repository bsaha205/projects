package ai.pkg3;

import ai.pkg3.Agent;

public class Solver {

    /*
	 * The starting point of the game.
	 * Instantiates two agents (human/ minimax/ alpha beta pruning/ or other) and pass them to a game object.
	 * Here a TickTackToe game is implemented as an example. You need to extend the abstract class Game to create your own game.
	 * */
    public static void main(String[] args) {

        Agent human = new HumanFIRAgent("Human");
        //Agent human = new MinimaxTTTAgent("007");
        Agent machine = new MinimaxFIRAgent("BOT");

        //System.out.println(human.name+" vs. "+machine.name);
        Game game = new FourInARow(human, machine);
        game.play();

    }

}
