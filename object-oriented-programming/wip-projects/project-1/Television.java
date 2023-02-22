
public class Television {
	private boolean power = false;
	private boolean mute = false;
	private int currentChannel = 1;
	private int prevChannel = 1;
	private int volume = 10;

	private final String tvCode;

	public Television(String code) {
		this.tvCode = code;
	}

	public String getTvCode() {
		return tvCode;
	}

	public void reciever(int channel) {
		if (power == false) {
			return;
		}

		channelChange(channel);
	}

	public void switchPower() {
		power = power ? false : true;

		if (power == false) {
			return;
		}

		displayState();
	}

	public void volumeUp() {
		if (power == false) {
			return;
		}
		else if (volume == 40 || mute) {
			displayState();
			return;
		}

		volume++;
		displayState();
	}

	public void volumeDown() {
		if (power == false) {
			return;
		}
		else if (volume == 0 || mute) {
			displayState();
			return;
		}

		volume--;
		displayState();
	}

	public void switchMute() {
		if (power == false) {
			return;
		}

		mute = mute ? false : true;
		displayState();
	}

	public void channelUp() {
		if (power == false) {
			return;
		}
		else if (currentChannel == 9999) {
			displayState();
			return;
		}

		prevChannel = currentChannel;
		currentChannel++;
		displayState();
	}

	public void channelDown() {
		if (power == false) {
			return;
		}
		else if (currentChannel == 1) {
			displayState();
			return;
		}

		prevChannel = currentChannel;
		currentChannel--;
		displayState();
	}

	public void channelChange(int channel) {
		if (power == false) {
			return;
		}
		else if (channel < 1 || channel > 9999) {
			System.out.println("Enter a valid number\n");
			displayState();
			return;
		}

		prevChannel = currentChannel;
		currentChannel = channel;
		displayState();
	}

	public void channelFlashback() {
		if (power == false) {
			return;
		}

		int temp = currentChannel;
		currentChannel = prevChannel;
		prevChannel = temp;
		displayState();
	}


	public void displayState() {
		System.out.printf("%s%s%n", "Television: ",tvCode);

		if (mute) {
			System.out.printf("%s%-5d%s%s", "Channel: ", currentChannel, "Volume: ", "Muted");
		}
		else {
			System.out.printf("%s%-5d%1s%d","Channel: ", currentChannel, "Volume: ", volume);
		}

		System.out.println();
		System.out.println();
	}
}