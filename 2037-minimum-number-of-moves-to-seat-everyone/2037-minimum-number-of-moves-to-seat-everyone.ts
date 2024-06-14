function minMovesToSeat(seats: number[], students: number[]): number {
    let freqSeats:number[] = Array(101).fill(0);
    let freqStudents:number[] = Array(101).fill(0);
    for(let i=0; i<students.length; i++){
        freqSeats[seats[i]]++;
        freqStudents[students[i]]++;
    }
    let i=0, j=0, ans = 0;
    while(i<101 && j<101){
        if(freqSeats[i] && freqStudents[j]){
            let moves = Math.min(freqSeats[i], freqStudents[j]);
            ans += moves*Math.abs(i-j);
            freqSeats[i]-=moves;
            freqStudents[j]-=moves;
        }
        else if(freqSeats[i]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
};