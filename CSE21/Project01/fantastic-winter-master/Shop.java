import java.util.Scanner;
public class Shop {
	public static int setup = 1;
	public static int buy = 2;
	public static int list;
	public static int checkout;
	public static double[] item_price;
	public static String[] item_name;
	public static int [] item_amount;
	public static int discount_amount;
	public static double discount_rate;
	public static int numItem = 0;
	
	public static void Intro1(Scanner input){
		System.out.println("This program supports 4 functions: ");
		System.out.println("\t1. Setup Shop\n\t2. Buy\n\t3. List Items\n\t4. Checkout");
		System.out.println("Please choose the function you want: ");
		setup = input.nextInt();
	}

	public static void Setup_Shop(Scanner input, int numItem){
			item_name = new String [numItem];
			item_price = new double [numItem];
			for (int i = 0; i < numItem; i++){
				System.out.println("Enter name of product " + i + ": ");
				item_name[i] = input.next();
				System.out.println("Enter price of product " + i + ": ");
				item_price[i] = input.nextDouble();
			}
			System.out.println("Please enter the amount to qualify for discount: ");
			discount_amount = input.nextInt();
			System.out.println("Please enter the discouint rate(0.1 for 10%): ");
			discount_rate = input.nextDouble();	
	}
	
	public static void Intro2(Scanner input){
		System.out.println("This program supports 4 functions: ");
		System.out.println("\t1. Setup Shop\n\t2. Buy\n\t3. List Items\n\t4. Checkout");
		System.out.println("Please choose the function you want: ");
		buy = input.nextInt();
	}
	
	public static void Buy(Scanner input, int numItem, String[] item_name){
		item_amount = new int [numItem];
		for(int i =0;i<numItem;i++){
			System.out.println("Enter the amount of " + item_name[i] + ": ");
			item_amount[i] = input.nextInt();
		}
	} 
	
	public static void Intro3(Scanner input){
		System.out.println("This program supports 4 functions: ");
		System.out.println("\t1. Setup Shop\n\t2. Buy\n\t3. List Items\n\t4. Checkout");
		System.out.println("Please choose the function you want: ");
		list = input.nextInt();
	}
	public static void List_item(String[] item_name1, double[] item_price1, int [] item_amount){
		double item_total_price =0;
		for (int i = 0; i < item_name1.length; i++){
			item_total_price = item_amount[i]*item_price[i];
			if (item_total_price > 0){
				System.out.println(item_amount[i] + " count of " + item_name[i] + " @ " + item_price [i] 
						+ " = $" + item_total_price);
			}
		}
	}
	
	public static String Checkout(){
		double discount = 0;
		double subTotal = 0;
		double total = 0;
		for (int i = 0; i < numItem; i++){
			subTotal += item_amount[i]*item_price[i];
		}
		if (subTotal > discount_amount){
			discount = subTotal * discount_rate;
		}else discount = 0;
		total = subTotal-discount;
		return "Thanks for coming!" + "\nSub Total: $" + subTotal 
				+ "\n-Discount: $" + discount + "\nTotal\t : $"
			    + total;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		do{
			Intro1(input);
			if (setup > 1 && setup <= 4){
				System.out.println("");
				System.out.println("Shop is not setup yet!");
				System.out.println("");
			}
			if (setup > 4){
				System.out.println("");
				System.out.println("Error: Do not know " + setup);
				System.out.println("");
			}
		}while (setup != 1);
		System.out.println("Please enter the number of items: ");
		numItem = input.nextInt();
		Setup_Shop(input, numItem);
		
		do{
			Intro2(input);
			if (buy == 1){
				System.out.println("Please enter the number of items: ");
				numItem = input.nextInt();
				Setup_Shop(input, numItem);
			}
			if (buy == 3 || buy == 4){
				System.out.println("");
				System.out.println("Try again: You have not bought anything");
				System.out.println("");
			}
			if (buy > 4){
				System.out.println("");
				System.out.println("Error: Do not know " + buy);
				System.out.println("");
			}
		}while (buy !=  2);
		Buy(input, numItem, item_name);
		
		do{
			Intro3(input);
			if (list == 2){
				Buy(input,numItem, item_name);
			}
			if (list == 3){
				List_item(item_name, item_price, item_amount);
			}
			if (list >= 5){
				System.out.println("");
				System.out.println("Error: Do not know " + buy);
				System.out.println("");
			}
		}while (list != 4);
		if (list == 4){
			System.out.println(Checkout());
		}
	}

}