import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Remote {
	private String remoteCode;

	public Remote(String tvCode) {
		this.remoteCode = tvCode;
	}

	public String getRemoteCode() {
		return remoteCode;
	}

	public void input(Button buttonCommand, ArrayList<Television> tvs) {
		int channel = 0;

		if (buttonCommand == Button.c) {
			try {
				channel = enterChannel();
			}
			catch (InputMismatchException excp) {
				System.out.println("Enter a number");
				System.out.println();
			}
		}

		final int inputChannel = channel;

		tvs.forEach((tv) -> {
			if (isPaired(tv) == false) {
				return;
			}

			switch (buttonCommand) {
				case d: {
					tv.channelDown();
					break;
				}
				case c: {
					tv.channelChange(inputChannel);
					break;
				}
				case u: {
					tv.channelUp();
					break;
				}
				case f: {
					tv.channelFlashback();
					break;
				}
				case m: {
					tv.switchMute();
					break;
				}
				case p: {
					tv.switchPower();
					break;
				}
				case o: {
					tv.volumeDown();
					break;
				}
				case i: {
					tv.volumeUp();
					break;
				}
			}
		});
	}

	private boolean isPaired(Television tv) {
		return tv.getTvCode() == this.getRemoteCode();
	}

	private static int enterChannel() {
		Scanner scan = new Scanner(System.in);

		System.out.print("Enter a channel (1 - 9999): ");

		int channel = scan.nextInt();
		System.out.println();

		return channel;
	}
}