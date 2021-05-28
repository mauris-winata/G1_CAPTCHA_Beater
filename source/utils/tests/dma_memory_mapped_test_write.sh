#!/bin/bash

transferSize=$1
transferCount=$2
h2cChannels=$3
c2hChannels=$4

tool_path=../tools

testError=0
# Run the PCIe DMA memory mapped write read test
echo "Info: Running PCIe DMA memory mapped write read test"
echo "      transfer size:  $transferSize"
echo "      transfer count: $transferCount"

# Write to all enabled h2cChannels in parallel
if [ $h2cChannels -gt 0 ]; then
  # Loop over four blocks of size $transferSize and write to them (in parallel where possible)
  for ((i=0; i<=0; i++))
  do
    addrOffset=$(($transferSize * $i))
    curChannel=$(($i % $h2cChannels))
    echo "Info: Writing to h2c channel $curChannel at address offset $addrOffset."
    $tool_path/dma_to_device -d /dev/xdma0_h2c_${curChannel} -f InputImage.bin -s $transferSize -a $addrOffset -c $transferCount &
    # If all channels have active transactions we must wait for them to complete
    if [ $(($curChannel+1)) -eq $h2cChannels ]; then
      echo "Info: Wait for current transactions to complete."
      wait
    fi 
  done
fi

if [ $h2cChannels -gt 0 ]; then
  # Loop over four blocks of size $transferSize and write to them (in parallel where possible)
  for ((i=0; i<=0; i++))
  do
    addrOffset=$(($transferSize * $i))
    curChannel=$(($i % $h2cChannels))
    echo "Info: Writing to h2c channel $curChannel at address offset $addrOffset."
    $tool_path/reg_rw /dev/xdma0_user 0x0 w 0x1
    # If all channels have active transactions we must wait for them to complete
    if [ $(($curChannel+1)) -eq $h2cChannels ]; then
      echo "Info: Wait for current transactions to complete."
      wait
    fi 
  done
fi

# Wait for the last transaction to complete.
wait

exit 0
