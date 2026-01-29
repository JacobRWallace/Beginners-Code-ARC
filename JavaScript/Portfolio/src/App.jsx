import { useState, useEffect } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'

function App() {
  const [count, setCount] = useState(0)
  const [intervalId, setIntervalId] = useState(null)
  const [intervalTime, setIntervalTime] = useState(500) // Default interval time in ms

  // Function to toggle auto-incrementing the count
  const toggleAutoIncrement = () => {
    if (intervalId) {
      clearInterval(intervalId)
      setIntervalId(null) // Stop the interval
    } else {
      const id = setInterval(() => {
        setCount((count) => count + 1)
      }, intervalTime) // Use the user-defined time interval
      setIntervalId(id)
    }
  }

  // Cleanup the interval when the component is unmounted or interval changes
  useEffect(() => {
    if (intervalId) {
      clearInterval(intervalId) // Clear the previous interval if one is active
      const newId = setInterval(() => {
        setCount((count) => count + 1)
      }, intervalTime) // Start a new interval with updated time
      setIntervalId(newId)
    }
    return () => {
      if (intervalId) {
        clearInterval(intervalId)
      }
    }
  }, [intervalTime])

  // Function to generate 50 characters before and 50 after the current count
  const generateUnicodeSequence = (currentCount) => {
    let before = [];
    let after = [];

    // Generate 50 characters before the current count
    for (let i = currentCount - 50; i < currentCount; i++) {
      before.push(String.fromCharCode(i));
    }

    // Generate 50 characters after the current count
    for (let i = currentCount + 1; i <= currentCount + 50; i++) {
      after.push(String.fromCharCode(i));
    }

    return { before, after };
  }

  const { before, after } = generateUnicodeSequence(count);

  return (
    <>
      <div>
        <a href="https://vitejs.dev" target="_blank">
          <img src={viteLogo} className="logo" alt="Vite logo" />
        </a>
        <a href="https://react.dev" target="_blank">
          <img src={reactLogo} className="logo react" alt="React logo" />
        </a>
      </div>
      <h1>Click the counter below!</h1>
      <div className="card">
        <button style={{ backgroundColor: 'red' }} onClick={() => setCount((count) => count - 1)}>
          Add -1
        </button>
        <tab> </tab>
        <button style={{ backgroundColor: 'green' }} onClick={() => setCount((count) => count + 1)}>
          Add +1
        </button>
        <p>Counter: {count}</p>

        {/* Display characters before, current, and after in a scrollable box array */}
        <div className="unicode-display">
          {before.map((char, index) => (
            <span className="unicode-box" key={`before-${index}`}>{char}</span>
          ))}
          <span className="unicode-box current">{String.fromCharCode(count)}</span>
          {after.map((char, index) => (
            <span className="unicode-box" key={`after-${index}`}>{char}</span>
          ))}
        </div>

        {/* Number input for interval time */}
        <label>
          Time Interval (ms): 
          <input
            type="number"
            value={intervalTime}
            onChange={(e) => setIntervalTime(Number(e.target.value))}
            style={{ marginLeft: '10px' }}
          />
        </label>
        <br />
        
        {/* Toggle button */}
        <button style={{ backgroundColor: 'cyan', marginTop: '10px' }} onClick={toggleAutoIncrement}>
          {intervalId ? 'Stop Auto Add' : 'Start Auto Add'}
        </button>
      </div>
      <p className="read-the-docs">
        Click on the Vite and React logos to learn more
      </p>
    </>
  )
}

export default App
