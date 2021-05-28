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


# Read from all enabled c2hChannels in parallel
if [ $c2hChannels -gt 0 ]; then
  # Loop over four blocks of size $transferSize and read from them (in parallel where possible)
  for ((i=1; i<=1; i++))
  do
    # addrOffset=$(($transferSize * $i))
    addrOffset=0
    curChannel=$(($i % $c2hChannels))
    rm -f output_result.bin
    echo "Info: Reading from c2h channel $curChannel at address offset $addrOffset."
    $tool_path/dma_from_device -d /dev/xdma0_c2h_${curChannel} -f output_result.bin -s $transferSize -a $addrOffset -c $transferCount &
    # If all channels have active transactions we must wait for them to complete
    if [ $(($curChannel+1)) -eq $c2hChannels ]; then
      echo "Info: Wait for the current transactions to complete."
      wait
    fi
  done
fi

# Wait for the last transaction to complete.
wait

exit 0
