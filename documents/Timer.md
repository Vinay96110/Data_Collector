✔ Description

Configures Timer 3 to provide accurate periodic triggers for ADC sampling.
Ensures ADC conversions occur at a fixed rate, critical for vibration analysis.
✔ Key Parameters

Prescaler = 84 - 1 → Generates a 1 MHz timer clock.
Period = 1000 - 1 → Produces a 1 kHz trigger signal (1 ms sampling interval).
TIM_TRGO_UPDATE → Configures Timer 3 to trigger ADC on update event.
✔ Reasoning

External trigger via Timer 3 provides consistent ADC sampling timing.
Accurate sampling rate is essential for vibration analysis to capture detailed waveform data.