void nextPerm(vector<int> &nums)
{
    int ano = n - 1;

    while (ano > 0 && nums[ano] <= nums[ano - 1])
    {
        ano--;
    }
    if (ano == 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        int pin = n - 1;

        while (pin > ano && nums[pin] <= nums[ano - 1])
        {
            pin--;
        }
        swap(nums[ano - 1], nums[pin]);
        reverse(nums.begin() + ano, nums.end());
    }

    return nums;
}