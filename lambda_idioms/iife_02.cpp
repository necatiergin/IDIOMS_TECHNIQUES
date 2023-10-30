auto f = [](auto x) {}

const int i = [&]{

    int i = some_default_value;

    if(someConditionIstrue)
    {
        Do some operations and calculate the value of i;
        i = some calculated value;
    }

    return i;

} (); 
