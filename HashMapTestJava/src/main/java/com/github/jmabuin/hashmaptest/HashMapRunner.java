package com.github.jmabuin.hashmaptest;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class HashMapRunner {

    private HashMapTestOptions options;

    private HashMap<Integer, List<Location>> map;

    public HashMapRunner(HashMapTestOptions options) {
        this.options = options;
        this.map = new HashMap<Integer, List<Location>>();
    }

    public void run() {

        if (this.options.getInput_file().isEmpty()) {
            System.out.println("Input file is empty. Aborting");
            System.exit(1);
        }

        long initTime = System.nanoTime();
        this.read_data();
        long endTime = System.nanoTime();

        System.out.println("Elapsed time in reading data: " + ((endTime - initTime) / 1e9) + " seconds");
        System.out.println("Size of HashMap is: " + this.map.size());

        initTime = System.nanoTime();
        this.access_data();
        endTime = System.nanoTime();
        System.out.println("Elapsed time in accessing data: " + ((endTime - initTime) / 1e9) + " seconds");

    }

    private void read_data() {
        try{
            BufferedReader br = new BufferedReader(new FileReader(this.options.getInput_file()));

            StringBuffer strBuffer = new StringBuffer();

            //strBuffer.append(br.readLine());
            String line = br.readLine();
            //String[] values;
            List<String> partes = new ArrayList<String>();
            List<String> values = new ArrayList<String>();

            while (line != null) {
                partes.addAll(Arrays.asList(line.split(":")));

                int key = Integer.parseInt(partes.get(0));

                this.map.put(key, new ArrayList<Location>());

                values.addAll(Arrays.asList(partes.get(1).split(";")));
                System.out.println(key + ": Number of items " + values.size());

                for (int i = 0; i< values.size(); i+=2) {
                    this.map.get(key).add(new Location(Integer.parseInt(values.get(i)), Integer.parseInt(values.get(i+1))));
                }

                partes.clear();
                values.clear();
                line = br.readLine();
            }

            br.close();

        }
        catch (IOException e) {
            System.err.println("Can not read input file " + this.options.getInput_file());
            e.printStackTrace();
        }
    }

    private void access_data() {

        Random rand = new Random();

        //int  n = rand.nextInt(50) + 1;
        int random_number; // rand() return a number between ​0​ and RAND_MAX
        int random_list_item;

        double result = 0.0;

        for (int i = 0; i< this.map.size(); ++i) {
            random_number = rand.nextInt(this.map.size());
            random_list_item = rand.nextInt(this.map.get(random_number).size());
            result = this.map.get(random_number).get(random_list_item).targetId - result + this.map.get(random_number).get(random_list_item).windowId;
        }

        System.out.println("Obtained result is: " + result);

    }


}
