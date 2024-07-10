下载地址：https://developer.nvidia.com/gameworksdownload
## Nsight System使用
```bash
nsys profile --trace=cuda,nvtx -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx  -gpu-metrics-device=0 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx  -gpu-metrics-device=1 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx,osrt,cudnn  -gpu-metrics-device=0,1 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys profile --trace=cuda,cublas,nvtx,osrt,cudnn  -gpu-metrics-device=0,1,2,3 --stats=false -o nsight_systems_report ./cudaProgramOut
nsys status -e
```

## Nsight Compute使用

```bash
ncu -o profile ./cudaProgramOut

ncu --set full --section MemoryWorkloadAnalysis_Tables -o profile ./cudaProgramOut

# 多卡 profile
ncu --replay-mode application --app-replay-mode relaxed --set full --section MemoryWorkloadAnalysis_Tables -o ./cudaProgramOut

```
```bash
ncu --list-[optional] # 显示可选指令， 'list-chips', 'list-metrics', 'list-rules', 'list-sections', and 'list-sets'
ncu --list-sets # 执行后，结果如下：

---------- --------------------------------------------------------------------------- ------- -----------------
Identifier Sections                                                                    Enabled Estimated Metrics
---------- --------------------------------------------------------------------------- ------- -----------------
basic      LaunchStats, Occupancy, SpeedOfLight                                        yes     45
detailed   ComputeWorkloadAnalysis, LaunchStats, MemoryWorkloadAnalysis, MemoryWorkloa no      193
           dAnalysis_Chart, Occupancy, SourceCounters, SpeedOfLight, SpeedOfLight_Roof
           lineChart
full       ComputeWorkloadAnalysis, InstructionStats, LaunchStats, MemoryWorkloadAnaly no      253
           sis, MemoryWorkloadAnalysis_Chart, MemoryWorkloadAnalysis_Tables, NumaAffin
           ity, Nvlink_Tables, Nvlink_Topology, Occupancy, SchedulerStats, SourceCount
           ers, SpeedOfLight, SpeedOfLight_RooflineChart, WarpStateStats
nvlink     Nvlink, Nvlink_Tables, Nvlink_Topology                                      no      22
roofline   SpeedOfLight, SpeedOfLight_HierarchicalDoubleRooflineChart, SpeedOfLight_Hi no      59
           erarchicalHalfRooflineChart, SpeedOfLight_HierarchicalSingleRooflineChart,
           SpeedOfLight_HierarchicalTensorRooflineChart, SpeedOfLight_RooflineChart

```


