int singleNonDuplicate(int* nums, int numsSize) {
    // int ans = 0;
    // for(int i = 0 ; i<numsSize ; i++){
    //     ans = ans ^ nums[i];
    // }
    // return ans;

    if(numsSize == 1)
        return nums[0];

    int low = 0;
    int high = numsSize -1 ;
    
    while(low <= high){
        int mid = low + (high-low)/2;

        if(mid == 0 && nums[0] != nums[1])
            return nums[0];
        if(mid == numsSize-1 && nums[numsSize-1] != nums[numsSize-2])
            return nums[numsSize-1];

        if(nums[mid+1] != nums[mid] && nums[mid-1] != nums[mid])
            return nums[mid];

        if(mid % 2 == 0){
            if(nums[mid-1] == nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            if(nums[mid-1] == nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}