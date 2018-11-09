package com.github.jmabuin.hashmaptest;

import org.apache.commons.cli.*;

import java.util.Arrays;

public class HashMapTestOptions {


    private Options options = null;

    private EnumModes.Mode operation_mode;

    private String correctUse =
            "java -jar HashMapTestJava-0.3.0.jar";// [SparkBWA Options] Input.fastq [Input2.fastq] Output\n";


    // Header to show when the program is not launched correctly
    private String header = "\tMetaCacheSpark performs metagenomics ...\nAvailable operating modes are:\n";

    // Footer to show when the program is not launched correctly
    private String footer = "\nPlease report issues at josemanuel.abuin@usc.es";

    private String input_file;
    private long map_size = 1000000;
    private long list_size = 256;

    public HashMapTestOptions(String[] args) {

        //Parse arguments
        for (String argument : args) {
            System.out.println("["+this.getClass().getName()+"] :: Received argument: " + argument);
        }

        this.options = this.initOptions();

        //Parse the given arguments
        CommandLineParser parser = new BasicParser();
        CommandLine cmd = null;

        this.operation_mode = EnumModes.Mode.HELP;

        try {
            cmd = parser.parse(this.options, args, true);

            //We look for the operation mode
            if (cmd.hasOption('h') || cmd.hasOption("help")) {
                //Case of showing the help
                this.operation_mode = EnumModes.Mode.HELP;
            }
            else {
                if (cmd.hasOption('m') || cmd.hasOption("mode")) {
                    // Choose the mode
                    String selected_mode = cmd.getOptionValue("mode");

                    switch (selected_mode) {
                        case "hashmap":
                            this.operation_mode = EnumModes.Mode.HASHMAP;
                            break;
                        case "guava":
                            this.operation_mode = EnumModes.Mode.GUAVA;
                            break;
                        case "native":
                            this.operation_mode = EnumModes.Mode.NATIVE;
                            break;
                        default:
                            this.operation_mode = EnumModes.Mode.HELP;
                            break;

                    }
                }
                else {
                    this.operation_mode = EnumModes.Mode.HELP;
                }

                if (cmd.hasOption('i') || cmd.hasOption("input_file")) {

                    this.input_file = cmd.getOptionValue("input_file");

                }
                else {
                    System.out.println("No input file selected. Aborting");
                    System.exit(1);
                }

                if ( cmd.hasOption('s') || cmd.hasOption("map_size")) {
                    this.map_size = Long.parseLong(cmd.getOptionValue("map_size"));
                }

                if ( cmd.hasOption('l') || cmd.hasOption("list_size")) {
                    this.list_size = Long.parseLong(cmd.getOptionValue("list_size"));
                }

            }


        }
        catch (UnrecognizedOptionException e) {
            e.printStackTrace();
            //formatter.printHelp(correctUse, header, options, footer, true);

            System.exit(1);


        } catch (MissingOptionException e) {
            //formatter.printHelp(correctUse, header, options, footer, true);
            System.exit(1);
        } catch (ParseException e) {
            //formatter.printHelp( correctUse,header, options,footer , true);
            e.printStackTrace();
            System.exit(1);
        }
    }

    /**
     * Function to init the MetaCache available options
     *
     * @return An Options object containing the available options
     */
    public Options initOptions() {

        Options privateOptions = new Options();

        //OptionGroup modes = new OptionGroup();

        Option help = new Option("h","help", false,"Shows documentation");
        privateOptions.addOption(help);

        Option mode = new Option("m", "mode", true, "Operation mode to use with HashMapTestJava.\nAvailable options are: hashmap, guava.");
        privateOptions.addOption(mode);

        Option input_file = new Option("i", "input_file", true, "Input file");
        privateOptions.addOption(input_file);

        Option map_size = new Option("s", "map_size", true, "Number of items in the hashmap");
        //taxonomy.setRequired(true);
        privateOptions.addOption(map_size);

        Option list_size =  new Option("l", "list_size", true, "Number of items in the list of each entry of the hashmap.");
        privateOptions.addOption(list_size);

        return privateOptions;
    }

    public EnumModes.Mode getMode() {
        return this.operation_mode;
    }

    public void printHelp() {
        //To print the help
        HelpFormatter formatter = new HelpFormatter();
        //formatter.setWidth(500);
        formatter.printHelp( correctUse,header, this.options,footer , true);

    }

    public EnumModes.Mode getOperation_mode() {
        return operation_mode;
    }

    public String getInput_file() {
        return input_file;
    }

    public long getMap_size() {
        return map_size;
    }

    public long getList_size() {
        return list_size;
    }
}
