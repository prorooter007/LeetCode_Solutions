#include<bits/stdc++.h>
using namespace std;

  class MountainArray {
    public:
      int get(int index);
      int length();
 };


class Solution {
public:
    int peakIndexInMountain(MountainArray &mountainArr){
        int n = mountainArr.length();
        int l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    int binarySearch(MountainArray &mountainArr,int l,int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
    int reversebinarySearch(MountainArray &mountainArr,int l,int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // int mini = INT_MAX;
        // for(int i = 0; i < mountainArr.length(); i++){
        //     if(mountainArr.get(i) == target){
        //         mini = min(mini, i);
        //     }
        // }
        // if(mini == INT_MAX) return -1;
        // return mini;
        // ios_base::sync_with_stdio(false);
        int n = mountainArr.length();
        int idx = peakIndexInMountain(mountainArr);
        int result_idx = binarySearch(mountainArr, 0, idx,target);
        if(result_idx != -1){
            return result_idx;
        }
        result_idx = reversebinarySearch(mountainArr, idx+1, n-1,target);
        return result_idx;   
    }
};