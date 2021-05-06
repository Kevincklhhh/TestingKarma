# ./run_drivers.sh karma-tenants10-dur15-c100 128.84.155.69 9090 9091 /home/midhul/snowflake_demands_nogaps10_15min.pickle $((128 * 1024)) /home/midhul/nfs/jiffy_dump 1 0

function cleanup() {
    killall python3;
    echo "Cleaned up";
}

trap cleanup EXIT

cleanup;

config=$1
dir_host=$2
dir_porta=$3
dir_portb=$4
trace_file=$5
block_size=$6
backing_path=$7
num_threads=$8
oracle=$9
alt_file="${10}"
selfish_file="${11}"
alloc="${12}"
init_credits="${13}"
public_blocks="${14}"
guarantee="${15}"
estimator="${16}"
error="${17}"
# tenant_ids=('92' '45' '14' '79' '93' '1' '54' '96' '44' '76')
# tenant_ids=('0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14' '15' '16' '17' '18' '19' '20' '21' '22' '23' '24' '25' '26' '27' '28' '29' '30' '31' '32' '33' '34' '35' '36' '37' '38' '39' '40' '41' '42' '43' '44' '45' '46' '47' '48' '49' '50' '51' '52' '53' '54' '55' '56' '57' '58' '59' '60' '61' '62' '63' '64' '65' '66' '67' '68' '69' '70' '71' '72' '73' '74' '75' '76' '77' '78' '79' '80' '81' '82' '83' '84' '85' '86' '87' '88' '89' '90' '91' '92' '93' '94' '95' '96' '97' '98' '99')
# alt_tenants=('50' '51' '52' '53' '54' '55' '56' '57' '58' '59' '60' '61' '62' '63' '64' '65' '66' '67' '68' '69' '70' '71' '72' '73' '74' '75' '76' '77' '78' '79' '80' '81' '82' '83' '84' '85' '86' '87' '88' '89' '90' '91' '92' '93' '94' '95' '96' '97' '98' '99')
# selfish_tenants=('0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '10' '11' '12' '13' '14' '15' '16' '17' '18' '19' '20' '21' '22' '23' '24' '25' '26' '27' '28' '29' '30' '31' '32' '33' '34' '35' '36' '37' '38' '39' '40' '41' '42' '43' '44' '45' '46' '47' '48' '49')

python3 compute_allocations.py $config $trace_file $alloc 100 $init_credits $public_blocks $guarantee $oracle $estimator $error $alt_file $selfish_file
echo "Allocations computed"

mapfile -t alt_tenants < $alt_file;
mapfile -t selfish_tenants < $selfish_file;

pids=()

echo "Starting altruistic tenants"
for tenant in "${alt_tenants[@]}"
do
    python3 -u driver.py $dir_host $dir_porta $dir_portb $tenant $num_threads $trace_file $block_size $backing_path $oracle 0 "/home/ubuntu/karma-eval/$config.alloc" > ~/karma-eval/$config.tenant$tenant.txt 2>&1 &
    pids+=($!);
    echo "Launched tenant$tenant";
done

echo "---------"
echo "Starting selfish tenants"

for tenant in "${selfish_tenants[@]}"
do
    python3 -u driver.py $dir_host $dir_porta $dir_portb $tenant $num_threads $trace_file $block_size $backing_path $oracle 1 "/home/ubuntu/karma-eval/$config.alloc" > ~/karma-eval/$config.tenant$tenant.txt 2>&1 &
    pids+=($!);
    echo "Launched tenant$tenant";
done

for pid in ${pids[*]}; do
    wait $pid
done

echo "Done"
