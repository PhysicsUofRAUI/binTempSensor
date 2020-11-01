# Short Brief
This directory is meant to hold the code that will be deployed, or used to test the setup. Currently the deployment code is held in this very directory, instead of an inner directory, and the test code is held in the test directory. For this code to compile correctly it has to be run in the Arduino IDE. If the code is not run in the Arduino IDE the needed libraries will not be found please see the how-to docs to learn more.

## Deployment Code
### one_bin
This holds the code to control a single bin. Below is a table describing where Arduino is expecting all the sensors to be connected (a how-to doc will be written about sensor wiring).

| Pin | Location      |
| --- | ------------- |
| 0   | Top of bin    |
| 1   | Middle of bin |
| 2   | Bottom of bin |

### two_bins
This holds the code to control a two bins. Below is a table describing where Arduino is expecting all the sensors to be connected (a how-to doc will be written about sensor wiring).

| Pin | Location          |
| --- | ----------------- |
| 0   | Top of bin one    |
| 1   | Middle of bin one |
| 2   | Bottom of bin one |
| 3   | Top of bin two    |
| 4   | Middle of bin two |
| 5   | Bottom of bin two |

### three_bins
This holds the code to control a three bins. Below is a table describing where Arduino is expecting all the sensors to be connected (a how-to doc will be written about sensor wiring).

| Pin | Location            |
| --- | ------------------- |
| 0   | Top of bin one      |
| 1   | Middle of bin one   |
| 2   | Bottom of bin one   |
| 3   | Top of bin two      |
| 4   | Middle of bin two   |
| 5   | Bottom of bin two   |
| 6   | Top of bin three    |
| 7   | Middle of bin three |
| 8   | Bottom of bin three |

### four_bins
This holds the code to control a four bins. Below is a table describing where Arduino is expecting all the sensors to be connected (a how-to doc will be written about sensor wiring).

| Pin  | Location            |
| ---- | ------------------- |
| 0    | Top of bin one      |
| 1    | Middle of bin one   |
| 2    | Bottom of bin one   |
| 3    | Top of bin two      |
| 4    | Middle of bin two   |
| 5    | Bottom of bin two   |
| 6    | Top of bin three    |
| 7    | Middle of bin three |
| 8    | Bottom of bin three |
| 9    | Top of bin four     |
| 10   | Middle of bin four  |
| 11   | Bottom of bin four  |

## Test Code
Currently there is only one test, and that one is a test of the custom library and this style of the code. A how-to doc will be included in the how_to_docs directory.

## Future Additions
When the new iterations are being developed new folders in the test directory will be included, and I will do my best to document what they are and what they are doing. Once deployment code has been developed for the new iterations new folders will appear to hold the deployment code so that the code for the different iterations are held separately. 
